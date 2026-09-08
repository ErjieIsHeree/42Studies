from pydantic import BaseModel, Field


from .hub import Hub
from .connection import Connection


class Drone(BaseModel):
    number: int = Field(gt=0)
    location: Hub | Connection
    pass
