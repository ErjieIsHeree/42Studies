
from call_me_maybe.infrastructure.application.domain import (
    FileReader,
    FileWriter,
    LLMClient
)


class ProcessFunctionCalling():
    """This method orquestrates the inputs, generates an adequate answer and
    outputs it.

    Args:
        prompt_repository (FileReader): The prompts file reader
        func_defs_repository (FileReader): The function definitions file reader
        llm_client (LLMClient): The LLM wrapper with a constraint decoding
        writer (FileWriter): The file 
    """
    def __init__(
        self,
        prompt_repository: FileReader,
        func_defs_repository: FileReader,
        llm_client: LLMClient,
        writer: FileWriter
    ):
        self.prompt_repository = prompt_repository
        self.func_defs_repository = func_defs_repository
        self.llm_client = llm_client
        self.writer = writer

    def execute(self) -> None:
        """This method executes the class objective."""
        prompts = self.prompt_repository.read()
        functions = self.func_defs_repository.read()
        result = self._generate_answer(prompts, functions)
        self.writer.write(result)

    def _generate_answer(self, prompts: str, functions: str) -> str:
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
        return ""
