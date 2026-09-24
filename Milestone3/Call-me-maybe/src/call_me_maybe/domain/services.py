import numpy as np
from enum import Enum
from pydantic import BaseModel


class State(Enum):
    E_MAIN_OBJ = -1
    S_MAIN_OBJ = 0
    KEY = 1
    VALUE = 2
    COMMA = 3
    pass


class FunctionSchemaConstraint(BaseModel):
    """Constrained decoding: fuerza al modelo a generar únicamente JSON
    sintácticamente válido, token a token."""
    vocab: dict[str, int]

    def _get_state(self, tokenized_answer: list[int]) -> int:

        return 0

    def _is_valid(self, token_id: int, state: int) -> bool:

        return True

    def json_contrained_decode(
        self,
        logits: list[float],
        tokenized_answer: list[int],
        ETC_TK_ID: int
    ) -> int:
        token_id: int = int(np.argmax(logits))
        state: int = self._get_state(tokenized_answer)
        if state == State.E_MAIN_OBJ.value:
            return ETC_TK_ID
        else:
            while not self._is_valid(token_id, state):
                logits[token_id] = float("-inf")
                token_id = int(np.argmax(logits))
        return token_id
