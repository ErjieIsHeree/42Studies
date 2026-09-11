from dataclasses import dataclass, field

from infrastructure.application.domain.hub import Hub


@dataclass
class Drone:
    id: int
    location: Hub
    in_connection: bool = field(init=False, default=False)
    pass
