import re
from enum import Enum
from pydantic import BaseModel, Field, model_validator

from .connection import Connection


class Zone(Enum):
    NORMAL = 0,
    BLOCKED = 1,
    RESTRICTED = 2,
    PRIORITY = 3,
    START = 10,
    END = 11


class Hub(BaseModel):
    name: str = Field(min_length=1)
    coordinates: tuple[int, int]
    zone: Zone
    color: str = Field(min_length=1)
    max_drones: int = Field(gt=0)

    connections: list[Connection] = Field(init=False)
    steps_left: int = Field(init=False, default=-1)

    @model_validator(mode="after")
    def _validate_hub_name(self) -> Hub:
        if re.findall(r"[\- ]", self.name):
            raise ValueError("Zone names can use any valid characters except d"
                             "ashes and spaces")
        return self
