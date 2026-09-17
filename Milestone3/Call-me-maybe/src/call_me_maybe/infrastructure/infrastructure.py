from call_me_maybe.infrastructure.application.domain import (
    FileReader,
    FileWriter,
    LLMClient
)


class JsonReader(FileReader):
    def __init__(self, filepath: str) -> None:
        super().__init__(filepath)

    def read(self) -> str:
        return ""


class JsonWriter(FileWriter):
    def __init__(self, filepath: str) -> None:
        self.filepath = filepath

    def write(self, result: str) -> None:
        return


class QwenLlm(LLMClient):
    def generate_logits(self, prompt: str, func_defs: str) -> list[float]:
        return []

    def tokenize(self, text: str) -> list[int]:
        return []
