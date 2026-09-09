from dataclasses import dataclass, field

from .hub import Hub, Zone
from .drone import Drone


@dataclass
class Simulator:
    nb_drones: int
    hubs: list[Hub]

    starter_hub: Hub = field(init=False)
    drones: list[Drone] = field(init=False, default_factory=list)

    def __post_init__(self):
        for hub in self.hubs:
            if hub.zone == Zone.START:
                self.starter_hub = hub
        for i in range(1, self.nb_drones + 1):
            self.drones += [Drone(i, self.starter_hub)]
    pass
