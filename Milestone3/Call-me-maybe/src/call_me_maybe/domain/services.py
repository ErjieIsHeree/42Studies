import re
import numpy as np
from typing import Any
from pydantic import BaseModel, ConfigDict, Field

from call_me_maybe.domain import CmmLlmClient


class StateMachine(BaseModel):
    """Drives the constrained decoding of an LLM answer.

    The machine walks through a fixed sequence of regular expressions, one
    per state, that describe what the generated text must look like at each
    step. Its job is to tell the caller which tokens should be forced and
    when the expected structure has been completed.
    """
    model_config = ConfigDict(arbitrary_types_allowed=True)

    llm: CmmLlmClient
    start_state: int = Field(init=False, default=0)
    end_state: int = Field(init=False, default=0)
    sequence: list[str] = Field(init=False, default_factory=list)

    def model_post_init(self, __context: Any) -> None:
        """Initializes the regex sequence that defines the state machine."""
        self.sequence: list[str] = [
            """{\n    "prompt": "[^\n]*\n$""",
            """    "name": \"""",
            """[^\n]*\n$""",
            """    "parameters": {\n       \"""",
            """[^\n]*,\n$""",
            """       \"""",
            """[^\n]*[^,]\n$""",
            """    }\n}\n"""
        ]
        self.end_state = len(self.sequence)

    def advance(self, state: int, txt: str) -> int:
        """Returns the next state if txt matches the current state's regex,
        otherwise the current state is kept."""
        if state == 4:
            if re.search(self.sequence[6], txt):
                return 7
        if re.search(self.sequence[state], txt):
            return state + 1
        return state

    def get_state_need(
            self, state: int, tk_prompt: list[int]) -> list[int] | None:
        """Returns the tokens to append for the given state.

        In forced states the tokens come from the regex itself, otherwise
        the most likely token is sampled from the model logits. Returns
        None when the state is out of range.
        """
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


def random_constrained_decode(logits: list[float]) -> int:
    """Picks the best token, repeatedly banning invalid ones, until the
    end-of-sequence token is the most likely one."""
    tk_id: int = int(np.argmax(logits))

    def valid(tk_id: int) -> bool:
        """Tells whether a token id is the accepted one."""
        return tk_id == 151658

    while not valid(tk_id):
        logits[tk_id] = float("-inf")
        tk_id = int(np.argmax(logits))
    return tk_id
