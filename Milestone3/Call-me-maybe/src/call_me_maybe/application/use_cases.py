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
    """This method orquestrates the inputs, generates an adequate answer and
    outputs it.

    Args:
        prompt_repository (FileReader): The prompts file reader
        func_defs_repository (FileReader): The function definitions file reader
        llm_client (LLMClient): The LLM wrapper with a constraint decoding
        writer (FileWriter): The file writer
    """
    model_config = ConfigDict(arbitrary_types_allowed=True)
    prompt_repository: FileReader
    func_defs_repository: FileReader
    llm_client: CmmLlmClient
    writer: FileWriter

    def execute(self) -> None:
        """This method executes the class objective."""
        prompts = self.prompt_repository.read()
        functions = self.func_defs_repository.read()
        result = self._generate_answer(prompts, json.dumps(functions))
        self.writer.write(result)

    def _generate_prompt_answer(
        self,
        tokenized_prompt: list[int]
    ) -> str:
        """Generates the constrained answer for a single tokenized prompt."""
        mc = StateMachine(llm=self.llm_client)
        state = 0

        def last_index(lst: list[int], value: int) -> int:
            """Returns the position of the last occurrence of value in lst"""
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
        """Data will be worked on in order to receive the required answer

        Using the LLMClient and the FunctionSchemaConstraint objects, this
        method will receive token by token and constraint decode them in order
        to follow the precised rules for the answer.

        Args:
            prompts (str): The user promptas in json
            functions (str): The functions that could correspond to the user
            prompt

        Return:
            str: The constrained complete answer of the LLM"""
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
