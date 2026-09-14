from dataclasses import dataclass, field

from infrastructure.application.domain.drone import Drone
from infrastructure.application.domain.hub import Hub, Zone
from infrastructure.application.domain.constants import (
    MISSING_HUBS_ERROR,
    ZERO_DRONES_ERROR,
)


@dataclass
class Simulator:
    """This class purpose is to simulates multiples drone flying in a
    coordinated manner exercise."""
    nb_drones: int
    hubs: list[Hub]

    starter_hub: Hub = field(init=False)
    end_hub: Hub = field(init=False)
    drones: list[Drone] = field(init=False, default_factory=list)

    def _validate_data(self) -> None:
        """
        This method validates no missing start or end hub.

        Notes:
            It is meant to be used first post_init
        """
        hubs_zones = [hub.zone for hub in self.hubs]
        if Zone.START not in hubs_zones or Zone.END not in hubs_zones:
            raise ValueError(MISSING_HUBS_ERROR)
        if self.nb_drones <= 0:
            raise ValueError(ZERO_DRONES_ERROR)
        return

    def _init_data(self) -> None:
        """This method is used to initialize uninitialized data."""
        for hub in self.hubs:
            if hub.zone == Zone.START:
                self.starter_hub = hub
            if hub.zone == Zone.END:
                self.end_hub = hub
        for i in range(1, self.nb_drones + 1):
            self.drones += [Drone(i, self.starter_hub)]
        return

    def _asign_steps_left(self) -> None:
        """This method is meant to initialize a data from the hubs."""
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

    def _delete_blocked_paths(self) -> None:
        """This method assign -1 to these ghost paths that leads to nowhere"""
        def rec_delete_path(hub: Hub) -> None:
            hub.steps_left = -1
            for next_hub, _ in hub.hubs:
                if (
                    next_hub.steps_left != -1 and
                    sum(
                        n2_hub.steps_left == -1
                        for n2_hub, _ in next_hub.hubs
                    ) < 2
                ):
                    rec_delete_path(next_hub)
            return

        for hub in self.hubs:
            if hub.zone == Zone.BLOCKED:
                rec_delete_path(hub)
        return

    def _check_possible_map(self) -> None:
        """Last check of the class to secure the map is valid."""
        if self.starter_hub.steps_left == -1:
            raise ValueError("[ERROR]: The map is impossible to solve.")
        return

    def __post_init__(self) -> None:
        """This method executes after the creation of the object and is meant
        to execute the methods above."""
        self._validate_data()
        self._init_data()
        self._asign_steps_left()
        self._delete_blocked_paths()
        self._check_possible_map()
        return

    def get_simulation(self) -> str:
        run: int = 0
        result: str = ""

        while any([drone.location != self.end_hub for drone in self.drones]):
            for i, drone in enumerate(self.drones):
                temp = drone.move_drone()
                if temp:
                    result += temp + " "
                if i >= run:
                    break
            run += 1
            result += f" {run} \n"
        return result
    pass
