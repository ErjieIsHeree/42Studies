import re


from infrastructure.application.domain import Simulator, Hub, Zone


class TxtParser():
    def get_simulator(self, file_dir: str) -> Simulator:
        line: str = ""
        nb_drones: int = 0
        hubs: list[Hub] = []

        i: int = 1

        def get_nb_drones(line: str) -> int:
            found = re.search(r"^nb_drones:\s+(\d+)\s+\n?$", line)
            if found:
                return int(found.group(1))
            else:
                raise Exception("Superimpossible regex error")

        def get_hub(line: str, line_nb: int) -> Hub:
            name: str = ""
            coordinates: tuple[int, int] = (0, 0)
            zone: Zone = Zone.NORMAL
            color: str = ""
            max_drones: int = 0

            hub_data = re.search(
                r"^(start_|end_)?hub:\s+(?P<name>.*?)\s+(?P<x>.*?)\s+(?P<y>.*?"
                r")(?:\s+\[(?:zone=(?P<zone>(?:normal|blocked|restricted|prior"
                r"ity))\s*)?(?:color=(?P<color>[a-zA-Z]+)\s*)?(?:max_drones=(?"
                r"P<max_drones>\d+))?\])?\s*\n?$",
                line
            )
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
                            f"[ERROR] at line {line_nb}: max_drones value must"
                            " be positive."
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
                        f"Error at line {line_nb}: This hub name is already in"
                        " use"
                    )
            return

        def connect_hubs(
            hub1: Hub,
            hub2: Hub,
            max_link_conn: int,
            line_nb: int
        ) -> None:
            for hub1_conns in hub1.hubs:
                hub1_conn, _ = hub1_conns
                if hub1_conn.name == hub2.name:
                    raise ValueError(
                        f"[ERROR] at line {line_nb}: The connection is repeate"
                        "d."
                    )
            for hub2_conns in hub2.hubs:
                hub2_conn, _ = hub2_conns
                if hub2_conn.name == hub2.name:
                    raise ValueError(
                        f"[ERROR] at line {line_nb}: The connection is repeate"
                        "d."
                    )
            hub1.hubs += [(hub2, max_link_conn)]
            hub2.hubs += [(hub1, max_link_conn)]
            return

        def create_connection(line: str, line_nb: int) -> None:
            hub1: Hub | None = None
            hub2: Hub | None = None
            max_link_capacity: int = 1

            # Get conn data
            conn_data = re.search(
                r"^.*?\s+(?P<hub1>.*?)\-(?P<hub2>.*?)(?:\s+\[max_link_capacity"
                r"=(?P<max_link_capacity>\d+)\])?\s*\n?$",
                line
            )
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
                            f"[ERROR] at line {line_nb}: max_link_capacity val"
                            "ue must be positive."
                        )
            # Check both hub exists
            if not hub1 or not hub2:
                print([hub.name for hub in hubs])
                raise ValueError(
                    f"[ERROR] at line {line_nb}: A hub or both of the connecti"
                    "on doesn't exist."
                )
            connect_hubs(hub1, hub2, max_link_capacity, line_nb)
            return

        with open(file_dir, "r") as f:
            # Getting nb of drones
            line = f.readline()
            while not re.fullmatch(r"^nb_drones:\s+\d+\s+\n?$", line):
                if line == "\n" or line.startswith('#'):
                    line = f.readline()
                elif not line:
                    raise ValueError("Empty file probided.")
                else:
                    raise ValueError(
                        f"Error at line {i}: First line must be 'nb_drones"
                        ": <number>'"
                    )
                i += 1
            nb_drones = get_nb_drones(line)
            for i, line in enumerate(f, i+1):
                # Getting hubs
                if line == "\n" or line.startswith('#'):
                    pass
                elif re.fullmatch(
                    r"^(?:start_|end_)?hub:\s+[^\s\-]+\s+\-?\d+\s+\-?\d+(?"
                    r":\s+\[(?:zone=(?:normal|blocked|restricted|priority)"
                    r"(?:\s+color=[a-zA-Z]+)?(?:\s+max_drones=\d+)?|color="
                    r"[a-zA-Z]+(?:\s+max_drones=\d+)?|max_drones=\d+)\])?"
                    r"\s*\n?$",
                    line
                ):
                    print(line)
                    hub = get_hub(line, i)
                    validate_hub(hub, i)
                    hubs += [hub]
                # Getting connections
                elif re.fullmatch(
                    r"^connection:\s+[^\s\-]+\-[^\s\-]+(\s+\[max_link_capa"
                    r"city=\d+\])?\s*\n?$",
                    line
                ):
                    create_connection(line, i)
                else:
                    raise ValueError(
                        f"Error at line {i}: The line must be empty, a com"
                        "ment (a line which starts with a '#') or a hub/co"
                        "connection. You can find the constraints of them "
                        "below:\n\nHub.\nhub: <name> <x_coordinate> <y_coo"
                        "rdinate> [zone=<normal|blocked|restricted|priorit"
                        "y> color=<string> max_drones=<positive_number>]\n"
                        "For starter and end hubs there is only one differ"
                        "ence between, they start with either start_hub or"
                        " end_hub correspondingly.\n\nConnection.\nconnect"
                        "ion: <hub1>-<hub2> [max_link_capacity=<positive_n"
                        "umber>]\nThe hubs must be created previously.\n\n"
                        "Take in mind that the data between the clasps are"
                        " optional, but must follow the same syntaxis. If "
                        "any is choosen."
                    )
        return Simulator(nb_drones, hubs)
