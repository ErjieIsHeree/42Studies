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

    The regexes describe the answer object, from the opening brace and the
    ``prompt`` field up to the closing braces:

    - states 0, 2, 4, 6: free states, the model samples the content.
    - states 1, 3, 5, 7: forced states, the structural tokens come from the
      regex itself.
    - ``end_state`` is the number of regexes, i.e. the state that means the
      answer is complete.
    """
    model_config = ConfigDict(arbitrary_types_allowed=True)

    llm: CmmLlmClient
    start_state: int = Field(init=False, default=0)
    end_state: int = Field(init=False, default=0)
    sequence: list[str] = Field(init=False, default_factory=list)

    def model_post_init(self, __context: Any) -> None:
        """Builds the regex sequence and records where the answer is complete.

        Fills ``sequence`` with one regex per state (see the class docstring)
        and sets ``end_state`` to the number of regexes, which is the state
        reached once the whole answer object has been generated.
        """
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
        """Returns the state to move to, given the state and the text so far.

        Args:
            state (int): The state the machine is currently in.
            txt (str): The answer text generated so far.

        Returns:
            int: The next state if ``txt`` matches the regex of ``state``,
            otherwise ``state`` itself, meaning the machine stays where it
            is and more tokens are needed.

        Notes:
            State 4 is a shortcut: if the last parameter line is already
            terminated without a trailing comma, the machine jumps straight
            to state 7 and closes the object, skipping the closing-quote
            states 5 and 6.
        """
        if state == 4:
            if re.search(self.sequence[6], txt):
                return 7
        if re.search(self.sequence[state], txt):
            return state + 1
        return state

    def get_state_need(
            self, state: int, tk_prompt: list[int]) -> list[int] | None:
        """Returns the tokens to append for the given state.

        In forced states (1, 3, 5 and 7) the tokens come from the regex
        itself, otherwise the most likely token is sampled from the model
        logits given the prompt generated so far.

        Args:
            state (int): The state the machine is currently in.
            tk_prompt (list[int]): The tokenized prompt and answer so far.

        Returns:
            list[int] | None: The token ids to append, or None when the
            state is out of range.
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
    end-of-sequence token is the most likely one.

    The logits are modified in place, since the current best token is
    replaced by ``-inf`` before the next one is picked, so the caller must
    pass a list it does not need to reuse.

    Args:
        logits (list[float]): The raw logits of the next token.

    Returns:
        int: The id of the end-of-sequence token, which is the token id
        151658 of the Qwen3 tokenizer.
    """
    tk_id: int = int(np.argmax(logits))

    def valid(tk_id: int) -> bool:
        """Tells whether a token id is the end-of-sequence one."""
        return tk_id == 151658

    while not valid(tk_id):
        logits[tk_id] = float("-inf")
        tk_id = int(np.argmax(logits))
    return tk_id
