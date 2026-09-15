from enum import Enum
from dataclasses import dataclass, field


class Zone(Enum):
    NORMAL = "normal"
    BLOCKED = "blocked"
    RESTRICTED = "restricted"
    PRIORITY = "priority"
    START = 1
    END = 2


ANSI_COLOR_CODES: dict[str, str] = {
    "black": "\033[30m",
    "red": "\033[31m",
    "green": "\033[32m",
    "yellow": "\033[33m",
    "blue": "\033[34m",
    "magenta": "\033[35m",
    "cyan": "\033[36m",
    "white": "\033[37m",
    "orange": "\033[38;5;208m",
    "brown": "\033[38;5;94m",
    "lime": "\033[38;5;118m",
    "gold": "\033[38;5;220m",
    "purple": "\033[38;5;141m",
    "violet": "\033[38;5;177m",
    "crimson": "\033[38;5;161m",
    "darkred": "\033[38;5;88m",
    "rainbow": "\033[38;5;201m",
}
ANSI_RESET = "\033[0m"


@dataclass
class Hub:
    name: str
    coordinates: tuple[int, int]
    zone: Zone
    color: str
    max_drones: int

    colored_name: str = field(init=False, default="")
    hubs: list[tuple["Hub", int]] = field(init=False, default_factory=list)
    steps_left: int = field(init=False, default=-1)

    def __post_init__(self) -> None:
        if self.color in ANSI_COLOR_CODES:
            self.colored_name = (f"{ANSI_COLOR_CODES[self.color]}{self.name}"
                                 f"{ANSI_RESET}")
        else:
            self.colored_name = self.name
        return
