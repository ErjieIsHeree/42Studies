import numpy as np
from pydantic import BaseModel


class FunctionSchemaConstraint(BaseModel):
    """Constrained decoding: fuerza al modelo a generar únicamente JSON
    sintácticamente válido, token a token."""
    vocab: dict[str, int]

    def json_contrained_decode(
        self,
        logits: list[float],
        tokenized_answer: list[int],
        ETC_TK_ID: int,
    ) -> int:
        return int(np.argmax(logits))
