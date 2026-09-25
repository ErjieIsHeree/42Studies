from abc import ABC, abstractmethod
from typing import Any


class FileReader(ABC):
    """This class describes how a file reader should work"""

    @abstractmethod
    def read(self) -> Any: ...


class FileWriter(ABC):
    """This class describes how a file writer should work"""

    @abstractmethod
    def write(self, txt: str) -> None: ...


class CmmLlmClient(ABC):
    """This abc class represents how a Call_Me_Maybe LLM should work"""
    STC_TK_ID: int
    ETC_TK_ID: int
    EOT_TK_ID: int

    @abstractmethod
    def generate_logits(self, tokenized_prompt: list[int]) -> list[float]: ...

    @abstractmethod
    def get_vocab(self) -> dict[Any, Any]: ...

    @abstractmethod
    def tokenize(self, text: str) -> list[int]: ...

    @abstractmethod
    def untokenize(self, tokens: list[int]) -> str: ...
