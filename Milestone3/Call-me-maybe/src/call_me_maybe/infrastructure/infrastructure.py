import sys
import json
from jsonschema import validate
from pydantic import BaseModel, ConfigDict, PrivateAttr

from call_me_maybe.infrastructure.application.domain import (
    FileReader,
    FileWriter,
    CmmLlmClient
)
from llm_sdk import Small_LLM_Model


class JsonReader(BaseModel, FileReader):
    """Class used to read and validate a Json, return it as a dict"""

    file_path: str
    json_schema: dict

    def read(self) -> dict:
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

        try:
            with open(self.file_path, "w") as f:
                f.write(txt)
        except Exception as err:
            print(f"[ERROR]: {err}")
            sys.exit(1)
        return


class QwenLlm(BaseModel, CmmLlmClient):
    """This class is a Small_LLM_Model wrapper to make it easier to use"""

    model_config = ConfigDict(arbitrary_types_allowed=True)
    _llm: Small_LLM_Model = PrivateAttr()

    def __init__(self, **data) -> None:
        super().__init__(**data)
        self._llm = Small_LLM_Model()

    def generate_logits(self, tokenized_prompt: list[int]) -> list[float]:
        """Generates the logits from the actual prompt"""
        return self._llm.get_logits_from_input_ids(tokenized_prompt)

    def tokenize(self, text: str) -> list[int]:
        """Converts the text into tokens"""
        return self._llm.encode(text)[0].tolist()

    def untokenize(self, tokens: list[int] | int) -> str:
        """Converts the tokens into text"""
        if isinstance(tokens, int):
            tokens = [tokens]
        return self._llm.decode(tokens)
