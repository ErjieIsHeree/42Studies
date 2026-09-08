from pydantic import BaseModel, Field, model_validator

from .hub import Hub, Zone
from .drone import Drone
from .connection import Connection


class Simulator(BaseModel):
    nb_drones: int = Field(gt=0)    # !! Add max?
    hubs: list[Hub]
    connections: list[Connection]

    starter_hub: Hub | None = Field(init=False, default=None)
    ending_hub: Hub | None = Field(init=False, default=None)
    hub_names: list[str] = Field(init=False)
    drones: list[Drone] = Field(init=False)

    @model_validator(mode="after")
    def _hub_names_init(self) -> Simulator:
        self.hub_names = [hub.name for hub in self.hubs]
        return self

    @model_validator(mode="after")
    def _validate_hubs(self) -> Simulator:
        if len(self.hubs) != len(set(self.hub_names)):
            raise ValueError("Zones names must be unique.")
        for hub in self.hubs:
            if hub.zone == Zone.START:
                if self.starter_hub is not None:
                    raise ValueError("Two starter hubs provided.")
                self.starter_hub = hub
            if hub.zone == Zone.END:
                if self.ending_hub is not None:
                    raise ValueError("Two ending hubs provided.")
                self.ending_hub = hub
        return self

    @model_validator(mode="after")
    def _validate_connections(self) -> Simulator:
        for conn in self.connections:
            hub1, hub2 = conn.name.split(sep="-")
            if hub1 not in self.hub_names or hub2 not in self.hub_names:
                raise ValueError("Zone wanted to connect doesn't exist.")
            for conn2 in self.connections:
                hub12, hub22 = conn2.name.split(sep="-")
                if hub1 == hub22 and hub2 == hub12:
                    raise ValueError("A connection appears twice.")
        return self

    @model_validator(mode="after")
    def _init_zones(self) -> Simulator:  # TODO give zones the steps left to en
        #   This connect all zones
        for hub in self.hubs:
            for conn in self.connections:
                hub1, hub2 = conn.name.split(sep="-")
                if hub == hub1 or hub == hub2:
                    hub.connections += [conn]
                    conn.hubs += [hub]
        #   This gives the corresponding steps left to each hub
        assert isinstance(self.ending_hub, Hub)
        self.ending_hub.steps_left = 0
        queue: list[Hub] = [self.ending_hub]
        restricteds_queue: list[Hub] = []
        count: int = 0
        while queue:
            # Add count to the already in queue hubs
            for rq_hub in restricteds_queue:
                rq_hub.steps_left = count
            for i, q_hub in enumerate(queue):
                if q_hub.zone is not Zone.RESTRICTED:
                    q_hub.steps_left = count
                else:
                    restricteds_queue += [q_hub]
            # Add new hubs
            for q_hub in queue:
                if q_hub.steps_left != -1:
                    for conn in q_hub.connections:
                        for conn_hub in conn.hubs:
                            if conn_hub.steps_left != -1:
                                queue += [conn_hub]
            # Delete old hubs from both queues(those with steps asigned)
            queue = [hub for hub in queue if hub.steps_left != -1]
            restricteds_queue = [hub for hub in restricteds_queue
                                 if hub.steps_left != -1]
            count += 1
        return self

    @model_validator(mode="after")
    def _init_drones(self) -> Simulator:
        assert isinstance(self.starter_hub, Hub)
        for i in range(1, self.nb_drones + 1):
            self.drones += [Drone(number=i, location=self.starter_hub)]
        return self

    def get_simulation(self) -> str:
        assert isinstance(self.ending_hub, Hub)
        simulation: str = ""

        while not all([drone.location.name == self.ending_hub.name
                       for drone in self.drones]):
            for drone in self.drones:
                # Check if a drone can move, if it can, move it and write the move "D<drone_id>-<zone> "
                simulation += "\n"
        return simulation
    pass
