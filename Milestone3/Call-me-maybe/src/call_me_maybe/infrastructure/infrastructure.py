import sys
import json
from typing import Any
from pathlib import Path
from jsonschema import validate
from pydantic import BaseModel, ConfigDict, Field

from call_me_maybe.domain import (
    FileReader,
    FileWriter,
    CmmLlmClient
)
from llm_sdk import Small_LLM_Model


class JsonReader(BaseModel, FileReader):
    """Class used to read and validate a Json, return it as a dict"""
    file_path: str
    json_schema: Any

    def read(self) -> Any:
        """This function validates and return the file_path as a dict"""

        try:
            with open(self.file_path, "r") as f:
                data = json.loads(f.read())
            validate(data, self.json_schema)
        except Exception as err:
            print(f"[ERROR]: {err}")
            sys.exit(2)
        return data


class JsonWriter(BaseModel, FileWriter):
    """Class used to write a string into a file"""
    file_path: str

    def write(self, txt: str) -> None:
        """Writes the txt string into file_path"""
        path = Path(self.file_path)
        path.parent.mkdir(parents=True, exist_ok=True)
        try:
            with open(path, "w") as f:
                f.write(txt)
        except Exception as err:
            print(f"[ERROR]: {err}")
            sys.exit(1)
        return


class QwenLlm(BaseModel, CmmLlmClient):
    """This class is a Small_LLM_Model wrapper to make it easier to use"""
    model_config = ConfigDict(arbitrary_types_allowed=True)

    llm: Small_LLM_Model = Field(init=False, default=Small_LLM_Model())
    STC_TK: str = Field(default=r"<tool_call>")
    ETC_TK: str = Field(default=r"</tool_call>")
    EOT_TK: str = Field(default=r"<|im_end|>")
    STC_TK_ID: int = Field(init=False, default=0)
    ETC_TK_ID: int = Field(init=False, default=0)
    EOT_TK_ID: int = Field(init=False, default=0)

    def model_post_init(self, __context: Any) -> None:
        """Encodes the special tokens once so their ids are ready to use."""
        self.STC_TK_ID = self.llm.encode(self.STC_TK).cpu()[0].tolist()[0]
        self.ETC_TK_ID = self.llm.encode(self.ETC_TK).cpu()[0].tolist()[0]
        self.EOT_TK_ID = self.llm.encode(self.EOT_TK).cpu()[0].tolist()[0]
        return

    def generate_logits(self, tokenized_prompt: list[int]) -> list[float]:
        """Generates the logits from the actual prompt"""
        return self.llm.get_logits_from_input_ids(tokenized_prompt)

    def get_vocab(self) -> dict[Any, Any]:
        """Reads and returns the LLM vocabulary file as a dict"""
        try:
            with open(self.llm.get_path_to_vocab_file(), "r") as f:
                vocab = json.loads(f.read())
        except Exception as err:
            print(f"[ERROR]: {err}")
            sys.exit(1)
        return vocab

    def tokenize(self, text: str) -> list[int]:
        """Converts the text into tokens"""
        return self.llm.encode(text).cpu()[0].tolist()

    def untokenize(self, tokens: list[int] | int) -> str:
        """Converts the tokens into text"""
        if isinstance(tokens, int):
            tokens = [tokens]
        return self.llm.decode(tokens)
