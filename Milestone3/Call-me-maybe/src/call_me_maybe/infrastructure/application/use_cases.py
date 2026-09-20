from pydantic import BaseModel, ConfigDict

from call_me_maybe.infrastructure.application.domain import (
    FileReader,
    FileWriter,
    CmmLlmClient
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
        result = self._generate_answer(prompts, functions)
        self.writer.write(result)

    def _generate_answer(self, prompts: dict, functions: dict) -> str:  # TODO
        """Data will be worked on in order to receive the required answer

        Using the LLMClient and the FunctionSchemaConstraint objects, this
        method will receive token by token and constraint decode them in order
        to follow the precised rules for the answer.

        Args:
            prompts (str): The user prompts in json
            functions (str): The functions that could correspond to the user
            prompt

        Return:
            str: The constrained complete answer of the LLM"""
        return "Hola!"
