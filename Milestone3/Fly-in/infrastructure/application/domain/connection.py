import re
from pydantic import BaseModel, model_validator, Field


class Connection(BaseModel):
    name: str = Field(min_length=3)
    max_capacity: int

    @model_validator(mode="after")
    def _validate_name(self) -> Connection:
        if len(re.findall(r"[/-]", self.name)) != 1:
            raise ValueError("Invalid connection name")
        return self
    pass
