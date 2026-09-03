from pydantic import BaseModel, Field, model_validator

from .hub import Hub
from .drone import Drone
from .connection import Connection


class Simulator(BaseModel):
    nb_drones: int = Field(gt=0)    # !! Add max?
    hubs: list[Hub]
    connections: list[Connection]

    hub_names: list[str] = Field(init=False)
    drones: Drone = Field(init=False)

    @model_validator(mode="after")
    def _hub_names_init(self) -> Simulator:
        self.hub_names = [hub.name for hub in self.hubs]
        return self

    @model_validator(mode="after")
    def _validate_hubs(self) -> Simulator:
        if len(self.hubs) != len(set(self.hub_names)):
            raise ValueError("Zones names must be unique.")
        return self

    @model_validator(mode="after")
    def _validate_connections(self) -> Simulator:
        for conn in self.connections:
            hub1, hub2 = conn.name.split(sep="-")
            if hub1 not in self.hub_names or hub2 not in self.hub_names:
                raise ValueError("Zone wanted to connect doesn't exist")
        return self

    @model_validator(mode="after")
    def _initialize(self) -> Simulator:   # TODO join hubs/conns & add drones
        return self
    pass


Simulator(connections=[], hubs=[], nb_drones=2)
