import re

from infrastructure.application.domain.simulator import Simulator
from infrastructure.application.domain.hub import Hub, Zone
from infrastructure.parsers.constants import (
    # Regex rules
    NB_DRONES_REGEX,
    SEARCH_NB_DRONES_REGEX,
    HUBS_REGEX,
    SEARCH_HUB_DATA_REGEX,
    CONNECTION_REGEX,
    SEARCH_CONNECTION_DATA_REGEX,

    # Errors
    EMPTY_FILE_ERROR,

    FIRST_LINE_ERROR,
    NEGATIVE_NB_DRONES_ERROR,

    FILE_CONSTRAINTS_ERROR,
    REPEATED_HUB_ID_ERROR,
    REPEATED_CONN_ERROR,
    NEGATIVE_MAX_LINK_CAPACITY_ERROR,
    UNEXISTING_CONN_ERROR
    )


class SimulatorConverter():
    def get_simulator(self, file_dir: str) -> Simulator:
        line: str = ""
        nb_drones: int = 0
        hubs: list[Hub] = []

        i: int = 1

        def get_nb_drones(line: str) -> int:
            found = re.search(SEARCH_NB_DRONES_REGEX, line)
            if found:
                return int(found.group("nb_drones"))
            else:
                raise Exception("Superimpossible regex error")

        def get_hub(line: str, line_nb: int) -> Hub:
            name: str = ""
            coordinates: tuple[int, int] = (0, 0)
            zone: Zone = Zone.NORMAL
            color: str = ""
            max_drones: int = 1

            hub_data = re.search(SEARCH_HUB_DATA_REGEX, line)
            if hub_data:
                name = hub_data.group("name")
                coordinates = (
                    int(hub_data.group("x")),
                    int(hub_data.group("y"))
                )
                if hub_data.group("zone"):
                    zone = Zone(hub_data.group("zone"))
                if hub_data.group("color"):
                    color = hub_data.group("color")
                if hub_data.group("max_drones"):
                    max_drones = int(hub_data.group("max_drones"))
                    if max_drones == 0:
                        raise ValueError(
                            NEGATIVE_NB_DRONES_ERROR.format(line_nb=line_nb)
                        )
            if re.match(r"start_", line):
                zone = Zone.START
            elif re.match(r"end_", line):
                zone = Zone.END
            return Hub(name, coordinates, zone, color, max_drones)

        def validate_hub(new_hub: Hub, line_nb: int) -> None:
            for hub in hubs:
                if new_hub.name == hub.name:
                    raise ValueError(
                        REPEATED_HUB_ID_ERROR.format(line_nb=line_nb))
            return

        def connect_hubs(
            hub1: Hub,
            hub2: Hub,
            max_link_conn: int,
            line_nb: int
        ) -> None:
            for hub in (hub1, hub2):
                for hub_conns in hub.hubs:
                    hub_conn, _ = hub_conns
                    if (
                        hub_conn.name == hub1.name or
                        hub_conn.name == hub2.name
                    ):
                        raise ValueError(
                            REPEATED_CONN_ERROR.format(line_nb=line_nb))
            hub1.hubs += [(hub2, max_link_conn)]
            hub2.hubs += [(hub1, max_link_conn)]
            return

        def create_connection(line: str, line_nb: int) -> None:
            hub1: Hub | None = None
            hub2: Hub | None = None
            max_link_capacity: int = 1

            # Get conn data
            conn_data = re.search(SEARCH_CONNECTION_DATA_REGEX, line)
            if conn_data:
                for hub in hubs:
                    if conn_data.group("hub1") == hub.name:
                        hub1 = hub
                    if conn_data.group("hub2") == hub.name:
                        hub2 = hub
                if conn_data.group("max_link_capacity"):
                    max_link_capacity = int(
                        conn_data.group("max_link_capacity"))
                    if max_link_capacity == 0:
                        raise ValueError(
                            NEGATIVE_MAX_LINK_CAPACITY_ERROR
                            .format(line_nb=line_nb)
                        )
            # Check both hub exists
            if not hub1 or not hub2:
                print([hub.name for hub in hubs])
                raise ValueError(UNEXISTING_CONN_ERROR.format(line_nb=line_nb))
            connect_hubs(hub1, hub2, max_link_capacity, line_nb)
            return

        with open(file_dir, "r") as f:
            # Getting nb of drones
            line = f.readline()
            while not re.fullmatch(NB_DRONES_REGEX, line):
                if line == "\n" or line.startswith('#'):
                    line = f.readline()
                elif not line:
                    raise ValueError(EMPTY_FILE_ERROR)
                else:
                    raise ValueError(FIRST_LINE_ERROR.format(i=i))
                i += 1
            nb_drones = get_nb_drones(line)
            for i, line in enumerate(f, i+1):
                # Getting hubs
                if line == "\n" or line.startswith('#'):
                    pass
                elif re.fullmatch(HUBS_REGEX, line):
                    hub = get_hub(line, i)
                    validate_hub(hub, i)
                    hubs += [hub]
                # Getting connections
                elif re.fullmatch(CONNECTION_REGEX, line):
                    create_connection(line, i)
                else:
                    raise ValueError(
                        FILE_CONSTRAINTS_ERROR.format(i=i))
        return Simulator(nb_drones, hubs)
