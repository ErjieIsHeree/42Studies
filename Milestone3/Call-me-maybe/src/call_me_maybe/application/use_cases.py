import json
from pydantic import BaseModel, ConfigDict

from call_me_maybe.domain import (
    FileReader,
    FileWriter,
    CmmLlmClient,
    StateMachine,
    S_PROMPT,
    E_PROMPT,
    random_constrained_decode
)


class ProcessFunctionCalling(BaseModel):
    """Orchestrates the inputs, generates an adequate answer and outputs it.

    Reads the prompts and the function definitions, feeds both to the LLM
    through the `StateMachine` constrained decoder, and writes the resulting
    list of function calls to the output.

    Args:
        prompt_repository (FileReader): The prompts file reader.
        func_defs_repository (FileReader): The function definitions file
        reader.
        llm_client (CmmLlmClient): The LLM wrapper driving the constrained
        decoding.
        writer (FileWriter): The file writer.
    """
    model_config = ConfigDict(arbitrary_types_allowed=True)
    prompt_repository: FileReader
    func_defs_repository: FileReader
    llm_client: CmmLlmClient
    writer: FileWriter

    def execute(self) -> None:
        """Executes the class objective.

        Reads both input files, generates one constrained answer per
        prompt, and writes the whole list as a JSON array.
        """
        prompts = self.prompt_repository.read()
        functions = self.func_defs_repository.read()
        result = self._generate_answer(prompts, json.dumps(functions))
        self.writer.write(result)

    def _generate_prompt_answer(
        self,
        tokenized_prompt: list[int]
    ) -> str:
        """Generates the constrained answer for a single tokenized prompt.

        Runs the state machine over the tokenized prompt, injecting the
        forced structural tokens and letting the model sample the free
        ones, until the answer object is complete.

        Args:
            tokenized_prompt (list[int]): The whole prompt, system template
            included, already tokenized.

        Returns:
            str: The generated answer object, as text.

        Raises:
            ValueError: If the end-of-text token is missing from the
            tokenized prompt.
            Exception: If the state machine asks for tokens in a state out
            of range.
        """
        mc = StateMachine(llm=self.llm_client)
        state = 0

        def last_index(lst: list[int], value: int) -> int:
            """Returns the position of the last occurrence of value in lst.

            Args:
                lst (list[int]): The list to search in.
                value (int): The value to look for.

            Returns:
                int: The position of the last occurrence of ``value``.

            Raises:
                ValueError: If ``value`` does not appear in ``lst``.
            """
            for i in range(len(lst) - 1, -1, -1):
                if lst[i] == value:
                    return i
            raise ValueError("[ERROR]: weird error")
        answer_indx: int = last_index(
            tokenized_prompt, self.llm_client.STC_TK_ID) + 1
        tokenized_answer: list[int] = tokenized_prompt[answer_indx:]

        while state != mc.end_state:
            tokens_id = mc.get_state_need(state, tokenized_prompt)
            if not tokens_id:
                raise Exception("Impossible.")
            tokenized_prompt += tokens_id
            tokenized_answer += tokens_id
            state = mc.advance(
                state, self.llm_client.untokenize(tokenized_answer))
        tokenized_answer += [random_constrained_decode(
            self.llm_client.generate_logits(tokenized_prompt))]
        return self.llm_client.untokenize(tokenized_answer[:-1])

    def _generate_answer(
        self,
        prompts: list[dict[str, str]],
        functions: str
    ) -> str:
        """Generates the constrained answers for every prompt.

        The functions catalogue is injected once into the system prompt,
        then every prompt is appended to a shared end prompt and decoded
        on its own through the `StateMachine` constrained decoder. The
        resulting objects are joined into a single JSON array.

        Args:
            prompts (list[dict[str, str]]): The user prompts, as read from
            the prompts file.
            functions (str): The functions that could correspond to the
            user prompt, as a JSON string.

        Returns:
            str: The constrained complete answers of the LLM, as a JSON
            array.
        """
        json_answer = ""
        tokenized_s_prompt = self.llm_client.tokenize(S_PROMPT.format(
            functions=functions))
        tokenized_e_prompt = self.llm_client.tokenize(E_PROMPT)
        for i, item in enumerate(prompts, 1):
            prompt = item["prompt"]
            json_answer += self._generate_prompt_answer(
                tokenized_s_prompt + self.llm_client.tokenize(prompt) +
                tokenized_e_prompt)
            if i < len(prompts):
                json_answer += ","
        return "[" + json_answer + "]"
