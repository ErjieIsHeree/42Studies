from abc import ABC, abstractmethod
from typing import Any


class FileReader(ABC):
    """This class describes how a file reader should work"""

    @abstractmethod
    def read(self) -> Any:
        """Reads the underlying content and returns it.

        Returns:
            Any: The parsed content of the file.
        """
        ...


class FileWriter(ABC):
    """This class describes how a file writer should work"""

    @abstractmethod
    def write(self, txt: str) -> None:
        """Writes the given text to the underlying destination.

        Args:
            txt (str): The text to write.
        """
        ...


class CmmLlmClient(ABC):
    """This abc class represents how a Call_Me_Maybe LLM should work.

    Attributes:
        STC_TK_ID (int): Id of the ``<tool_call>`` start token.
        ETC_TK_ID (int): Id of the ``</tool_call>`` end token.
        EOT_TK_ID (int): Id of the end-of-text token, which marks the end
        of a user turn inside the prompt.
    """
    STC_TK_ID: int
    ETC_TK_ID: int
    EOT_TK_ID: int

    @abstractmethod
    def generate_logits(self, tokenized_prompt: list[int]) -> list[float]:
        """Returns the model logits for the given tokenized prompt.

        Args:
            tokenized_prompt (list[int]): The token ids generated so far.

        Returns:
            list[float]: One raw logit per vocabulary entry, the last one
            being the score of the token to generate next.
        """
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
