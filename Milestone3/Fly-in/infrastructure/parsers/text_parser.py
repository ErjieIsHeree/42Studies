import re
from pydantic import BaseModel, model_validator


from ..application.domain.simulator import Simulator, Hub, Connection


class Parser(BaseModel):
    file_dir: str
    sim: Simulator

    @model_validator(mode="after")
    def _create_simulator(self) -> Parser:
        line: str = ""
        nb_drones: int = 0
        hubs: list[Hub] = []
        connections: list[Connection] = []

        def valid_connection(conn: Connection) -> bool:
            hub1_n, hub2_n = conn.name.split("-")
            hubs_names = {hub.name for hub in hubs}
            return hub1_n in hubs_names and hub2_n in hubs_names

        try:
            with open(self.file_dir, "r") as f:
                # Check nb of drones is first
                for line in f:
                    if not line or line.startswith('#'):
                        pass
                    elif re.fullmatch(r"nb_drones: \d+\n", line):
                        found = re.search(r"\d+", line)
                        if found:
                            nb_drones = int(found.group())
                    else:
                        raise ValueError("Expected \"nb_drones: <number of dro"
                                         f"nes>\" as first line, got: {line} i"
                                         "nstead.")
                # Check hubs are correctly created
                for line in f:
                    # controlar 7 casos (start_hub, hub, end_hub, connection, spaces&comments and others)
                    if line == "\n" or line.startswith('#'):
                        pass
                    elif re.fullmatch(
                        r"hub:\s+[^\s-]+\s+\-?\d+\s+\-?\d+(\s+\[.*\])\n?",
                        line
                    ):  # Hub case
                        found = re.search(
                            r"hub:\s+(.*)\s+(.*)\s+(.*)(?:\s+\[(.*)\])\n?",
                            line
                        )
                        
                    elif re.fullmatch(
                        r"connection:\s+[^\s\-]+\-[^\s\-]+(\s+\[max_link_capac"
                        r"ity=\d+\])?\n?",
                        line
                    ):  # Connection case
                        found = re.search(
                            r"connection:\s+(.*)\-(.*)(\s+)?",
                            line
                        )
                    elif re.fullmatch(
                        r"start_hub:\s+[^\s-]+\s+\-?\d+\s+\-?\d+"
                        r"(\s+\[.*\])\n?",
                        line
                    ):  # Start hub case
                        found = re.search(
                            r"",
                            line
                        )
                    elif re.fullmatch(
                        r"end_hub:\s+[^\s-]+\s+\-?\d+\s+\-?\d+(\s+\[.*\])\n?",
                        line
                    ):  # End hub case
                        found = re.search(
                            r"",
                            line
                        )
                    else:
                        raise ValueError(f"The line \"{line}\" doesn't follow "
                                         "the required constraints.")
        except Exception as err:
            print(f"[ERROR]: {err}")
        return self

    def get_drones_qty(self) -> int:
        return 0
    pass
