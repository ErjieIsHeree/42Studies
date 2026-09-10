from enum import Enum
from dataclasses import dataclass, field


class Zone(Enum):
    NORMAL = "normal"
    BLOCKED = "blocked"
    RESTRICTED = "restricted"
    PRIORITY = "priority"
    START = 1
    END = 2


@dataclass
class Hub:
    name: str
    coordinates: tuple[int, int]
    zone: Zone
    color: str
    max_drones: int

    hubs: list[tuple[Hub, int]] = field(init=False, default_factory=list)
    steps_left: int = field(init=False, default=-1)
