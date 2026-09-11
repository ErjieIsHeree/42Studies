from dataclasses import dataclass, field

from infrastructure.application.domain.drone import Drone
from infrastructure.application.domain.hub import Hub, Zone
from infrastructure.application.domain.constants import (
    MISSING_HUBS_ERROR,
    ZERO_DRONES_ERROR,
)


@dataclass
class Simulator:
    nb_drones: int
    hubs: list[Hub]

    starter_hub: Hub = field(init=False)
    end_hub: Hub = field(init=False)
    drones: list[Drone] = field(init=False, default_factory=list)

    def _validate_data(self) -> None:
        hubs_zones = [hub.zone for hub in self.hubs]
        if Zone.START not in hubs_zones or Zone.END not in hubs_zones:
            raise ValueError(MISSING_HUBS_ERROR)
        if self.nb_drones <= 0:
            raise ValueError(ZERO_DRONES_ERROR)
        return

    def _init_data(self) -> None:
        for hub in self.hubs:
            if hub.zone == Zone.START:
                self.starter_hub = hub
            if hub.zone == Zone.END:
                self.end_hub = hub
        for i in range(1, self.nb_drones + 1):
            self.drones += [Drone(i, self.starter_hub)]
        return

    def _asign_steps_left(self) -> None:
        steps_count: int = 0
        queue: list[Hub] = [self.end_hub]
        extra_queue: list[Hub] = []

        while queue or extra_queue:
            original_hubs: int = len(queue)
            original_res_hubs: int = len(extra_queue)
            temp_extra = list(extra_queue)

            for hub in temp_extra:
                if hub.steps_left == -1:
                    hub.steps_left = steps_count
                pass

            for hub in list(queue):
                if hub.zone == Zone.RESTRICTED:
                    extra_queue += [hub]
                else:
                    if hub.steps_left == -1:
                        hub.steps_left = steps_count
                        for new_hub, _ in hub.hubs:
                            if new_hub.steps_left == -1:
                                queue += [new_hub]
                pass

            for hub in temp_extra:
                if hub.steps_left != -1:
                    for new_hub, _ in hub.hubs:
                        if new_hub.steps_left == -1:
                            queue += [new_hub]
                pass

            for _ in range(original_hubs):
                queue.pop(0)
            for _ in range(original_res_hubs):
                extra_queue.pop(0)
            steps_count += 1
        return

    def __post_init__(self) -> None:
        self._validate_data()
        self._init_data()
        self._asign_steps_left()
        return
    pass
