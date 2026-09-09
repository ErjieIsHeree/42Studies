import re
from pydantic import BaseModel


from ..application.domain import Simulator, Hub, Zone


class TxtParser(BaseModel):
    def create_simulator(self, file_dir: str) -> Simulator:
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

        try:
            with open(file_dir, "r") as f:
                # Check nb of drones is first
                line = f.readline()
                while not re.fullmatch(r"^nb_drones:\s+\d+\s+\n?$", line):
                    if not line or line.startswith('#'):
                        line = f.readline()
                    else:
                        raise ValueError(
                            f"Error at line {i}: First line must be 'nb_drones"
                            ": <number>'"
                        )
                    i += 1
                nb_drones = get_nb_drones(line)
                # Get hubs
                for i, line in enumerate(f, i+1):
                    if re.fullmatch(
                        r"^hub:\s+[^\s\-]+\s+\-?\d+\s+\-?\d+(\s+\[.*?\])?"
                        r"\s*\n?$",
                        line
                    ):  # Hub case
                        found = re.search(
                            r"^hub:\s+(.*?)\s+(\-?\d+)\s+(\-?\d+)(?:\s+\[(.*?)"
                            r"\])?\s*\n?$",
                            line
                        )
                        # TODO create hub and save it
                    elif re.fullmatch(
                        r"^connection:\s+[^\s\-]+\-[^\s\-]+(\s+\[max_link_capa"
                        r"city=\d+\])?\s*\n?$",
                        line
                    ):  # Connection case
                        found = re.search(
                            r"^connection:\s+(.*?)\-(.*?)(?:\s+\[max_link_capa"
                            r"city=(\d+)\])?\s*\n?$",
                            line
                        )
                        # TODO create conn and save it
                    elif re.fullmatch(
                        r"^start_hub:\s+[^\s-]+\s+\-?\d+\s+\-?\d+(\s+\[.*?\])?"
                        r"\s*\n?$",
                        line
                    ):  # Start hub case
                        found = re.search(
                            r"^.*?\s+(.*?)\s+(.*)?\s+(.*?)(\s+\[(.*?)\])?"
                            r"\s*\n?$",
                            line
                        )
                        # TODO create start_hub and save it
                    elif re.fullmatch(
                        r"^end_hub:\s+[^\s-]+\s+\-?\d+\s+\-?\d+(\s+\[.*?\])?"
                        r"\s*\n?$",
                        line
                    ):  # Start hub case
                        found = re.search(
                            r"^.*?\s+(.*?)\s+(.*)?\s+(.*?)(\s+\[(.*?)\])?"
                            r"\s*\n?$",
                            line
                        )
                        # TODO end hub and save it
                    else:
                        raise ValueError(f"The line \"{line}\" doesn't follow "
                                         "the required constraints.")
        except Exception as err:
            print(f"[ERROR]: {err}")
        return Simulator(
            nb_drones=nb_drones,
            hubs=hubs,
            connections=connections
        )
