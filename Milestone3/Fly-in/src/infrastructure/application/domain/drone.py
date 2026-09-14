from dataclasses import dataclass, field

from infrastructure.application.domain.hub import Hub
from infrastructure.application.domain.hub import Zone


@dataclass
class Drone:
    id: int
    location: Hub
    in_connection: bool = field(init=False, default=False)

    def move_drone(self) -> str:

        if self.location.steps_left == 0:
            return ""

        def get_fastest_hub() -> Hub:
            fast_hub: Hub = self.location.hubs[0][0]
            for hub, _ in self.location.hubs:
                if (
                    hub.steps_left >= 0 and
                    hub.steps_left <= fast_hub.steps_left
                ):
                    if hub.steps_left == fast_hub.steps_left:
                        if hub.zone == Zone.PRIORITY:
                            fast_hub = hub
                    else:
                        fast_hub = hub
            return fast_hub

        if self.in_connection:
            self.in_connection = False
            return f"D{self.id}-{self.location.colored_name}"
        else:
            origin: Hub = self.location
            self.location = get_fastest_hub()
            if self.location.zone == Zone.RESTRICTED:
                self.in_connection = True
                return (f"D{self.id}-{origin.colored_name}-"
                        f"{self.location.colored_name}")
            else:
                return f"D{self.id}-{self.location.colored_name}"
    pass
