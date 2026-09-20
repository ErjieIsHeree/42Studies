from abc import ABC, abstractmethod


class FileReader(ABC):
    """This class describes how a file reader should work"""

    @abstractmethod
    def read(self) -> dict: ...


class FileWriter(ABC):
    """This class describes how a file writer should work"""

    @abstractmethod
    def write(self, txt: str) -> None: ...


class CmmLlmClient(ABC):
    """This abc class represents how a Call_Me_Maybe LLM should work"""

    @abstractmethod
    def generate_logits(self, tokenized_prompt: list[int]) -> list[float]: ...

    @abstractmethod
    def tokenize(self, text: str) -> list[int]: ...

    @abstractmethod
    def untokenize(self, tokens: list[int]) -> str: ...
