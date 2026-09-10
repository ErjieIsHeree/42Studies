from dataclasses import dataclass, field

from .hub import Hub


@dataclass
class Drone:
    id: int
    location: Hub
    in_connection: bool = field(init=False, default=False)
    pass
