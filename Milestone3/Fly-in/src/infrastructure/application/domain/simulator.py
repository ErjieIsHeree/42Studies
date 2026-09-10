from dataclasses import dataclass, field

from .hub import Hub, Zone
from .drone import Drone


@dataclass
class Simulator:
    nb_drones: int
    hubs: list[Hub]

    starter_hub: Hub = field(init=False)
    drones: list[Drone] = field(init=False, default_factory=list)

    def _validate_data(self) -> None:
        hubs_zones = [hub.zone for hub in self.hubs]
        if Zone.START not in hubs_zones or Zone.END not in hubs_zones:
            raise ValueError("[ERROR]: Missing start or end hubs.")
        if self.nb_drones <= 0:
            raise ValueError("[ERROR]: Simulation must have at least one drone.")
        return

    def _init_data(self) -> None:
        for hub in self.hubs:
            if hub.zone == Zone.START:
                self.starter_hub = hub
        for i in range(1, self.nb_drones + 1):
            self.drones += [Drone(i, self.starter_hub)]
        return

    def __post_init__(self) -> None:
        self._validate_data()
        self._init_data()
        # Create a function that maps the hubs assigning them their path value
        return
    pass
