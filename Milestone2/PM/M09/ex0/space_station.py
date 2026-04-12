from pydantic import BaseModel, Field
from datetime import datetime


class SpaceStation(BaseModel):
    station_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=1, max_length=50)
    crew_size: int = Field(ge=1, le=20)
    power_level: float = Field(ge=0.0, le=100.0)
    oxygen_level: float = Field(ge=0.0, le=100.0)
    last_maintenance: datetime
    is_operational: bool = Field(default=True)
    notes: str = Field(max_length=200, default="")
    pass


def main() -> None:
    space_station = SpaceStation(
        station_id="ISS001",
        name="International Space Station",
        crew_size=6,
        power_level=85.5,
        oxygen_level=92.3,
        last_maintenance=datetime(2020, 11, 26)
    )

    print(f"""Space Station Data Validation
========================================
Valid station created:
ID: {space_station.station_id}
Name: {space_station.name}
Crew: {space_station.crew_size} people
Power: {space_station.power_level}%
Oxygen: {space_station.oxygen_level}%
Status: {"Operational" if space_station.is_operational else "Not operational"}
""")

    try:
        SpaceStation(
            station_id="ISS001",
            name="International Space Station",
            crew_size=21,
            power_level=85.5,
            oxygen_level=92.3,
            last_maintenance=datetime(2020, 11, 26)
        )
    except Exception as err:
        print(f"""========================================
Expected validation error:
{err.errors()[0]["msg"]}""")
    pass


main()
