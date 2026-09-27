from abc import ABC, abstractmethod
from typing import Any


class FileReader(ABC):
    """This class describes how a file reader should work"""

    @abstractmethod
    def read(self) -> Any:
        """Reads the underlying content and returns it."""
        ...


class FileWriter(ABC):
    """This class describes how a file writer should work"""

    @abstractmethod
    def write(self, txt: str) -> None:
        """Writes the given text to the underlying destination."""
        ...


class CmmLlmClient(ABC):
    """This abc class represents how a Call_Me_Maybe LLM should work"""
    STC_TK_ID: int
    ETC_TK_ID: int
    EOT_TK_ID: int

    @abstractmethod
    def generate_logits(self, tokenized_prompt: list[int]) -> list[float]:
        """Returns the model logits for the given tokenized prompt."""
        ...

    @abstractmethod
    def get_vocab(self) -> dict[Any, Any]:
        """Returns the LLM vocabulary."""
        ...

    @abstractmethod
    def tokenize(self, text: str) -> list[int]:
        """Converts text into a list of token ids."""
        ...

    @abstractmethod
    def untokenize(self, tokens: list[int]) -> str:
        """Converts a list of token ids back into text."""
        ...
