from abc import ABC, abstractmethod


class FileReader(ABC):
    """"""
    def __init__(self, filepath: str) -> None:
        self.filepath = filepath

    @abstractmethod
    def read(self) -> str: ...


class FileWriter(ABC):
    """"""
    def __init__(self, filepath: str) -> None:
        self.filepath = filepath

    @abstractmethod
    def write(self, result: str) -> None: ...


class LLMClient(ABC):
    """"""
    @abstractmethod
    def generate_logits(self, prompt: str, func_defs: str) -> list[float]: ...

    @abstractmethod
    def tokenize(self, text: str) -> list[int]: ...

    @abstractmethod
    def untokenize(self, tokens: list[int]) -> str: ...
