import re
import numpy as np
from typing import Any
from pydantic import BaseModel, ConfigDict, Field

from call_me_maybe.domain import CmmLlmClient


class StateMachine(BaseModel):
    model_config = ConfigDict(arbitrary_types_allowed=True)

    llm: CmmLlmClient
    start_state: int = Field(init=False, default=0)
    end_state: int = Field(init=False, default=8)
    sequence: list[str] = Field(init=False, default_factory=list)

    def model_post_init(self, __context: Any) -> None:
        self.sequence: list[str] = [
            """{\n    "prompt":[^\n]*\n$""",
            """    "name":""",
            """[^\n]*\n$""",
            """    "parameters": {\n           """,
            """[^\n]*\n$""",
            """       """,
            """[^,\n]*\n$""",
            """    }\n}\n</tool_call>""",
        ]

    def advance(self, state: int, txt: str) -> int:
        if re.search(self.sequence[state], txt):
            return state + 1
        return state

    def get_state_need(
            self, state: int, tk_prompt: list[int]) -> list[int] | None:
        if state == 1:
            return self.llm.tokenize(self.sequence[1])
        elif state == 3:
            return self.llm.tokenize(self.sequence[3])
        elif state == 5:
            return self.llm.tokenize(self.sequence[5])
        elif state == 7:
            return self.llm.tokenize(self.sequence[7])
        elif state > 7 or state < 0:
            return None
        else:
            return [int(np.argmax(self.llm.generate_logits(tk_prompt)))]
