import json
from pydantic import BaseModel, ConfigDict

from call_me_maybe.domain import (
    FileReader,
    FileWriter,
    CmmLlmClient,
    FunctionSchemaConstraint,
    S_PROMPT,
    ANSWER_EXAMPLE,
    E_PROMPT
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
        tokenized_answer: list[int] = []
        constrainer = FunctionSchemaConstraint(
            vocab=self.llm_client.get_vocab())
        token_id = 1
        is_answer = False

        while (token_id != self.llm_client.EOT_TK_ID):
            logits = self.llm_client.generate_logits(tokenized_prompt)
            if not is_answer:
                token_id = logits.index(max(logits))
                tokenized_prompt += [token_id]
                if token_id == self.llm_client.STC_TK_ID:
                    is_answer = True
            else:
                token_id = constrainer.json_contrained_decode(
                    logits, tokenized_answer, self.llm_client.ETC_TK_ID)
                tokenized_prompt += [token_id]
                if token_id != self.llm_client.ETC_TK_ID:
                    tokenized_answer += [token_id]
                else:
                    is_answer = False
        print(self.llm_client.untokenize(tokenized_prompt))
        return self.llm_client.untokenize(tokenized_answer)

    def _generate_answer(self, prompts: list, functions: str) -> str:
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
            functions=functions, example=ANSWER_EXAMPLE))
        tokenized_e_prompt = self.llm_client.tokenize(E_PROMPT)
        for i, item in enumerate(prompts, 1):
            prompt = item["prompt"]
            json_answer += self._generate_prompt_answer(
                tokenized_s_prompt + self.llm_client.tokenize(prompt) +
                tokenized_e_prompt)
            if i < len(prompts):
                json_answer += ","
        return "[" + json_answer + "]"
