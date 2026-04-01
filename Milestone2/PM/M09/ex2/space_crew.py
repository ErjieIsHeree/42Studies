from enum import Enum
from pydantic import BaseModel, Field, model_validator
from datetime import datetime
from typing_extensions import Self


class Rank(Enum):
    CADET = "cadet"
    OFFICER = "officer"
    LIEUTENANT = "lieutenant"
    CAPTAIN = "captain"
    COMMANDER = "commander"
    pass


class CrewMember(BaseModel):
    member_id: str = Field(max_length=10, min_length=3)
    name: str = Field(max_length=50, min_length=2)
    rank: Rank
    age: int = Field(ge=18, le=80)
    specialization: str = Field(max_length=30, min_length=3)
    years_experience: int = Field(ge=0, le=50)
    is_active: bool = Field(default=True)
    pass


class SpaceMission(BaseModel):
    mission_id: str = Field(max_length=15, min_length=5)
    mission_name: str = Field(max_length=100, min_length=3)
    destination: str = Field(max_length=50, min_length=3)
    launch_date: datetime
    duration_days: int = Field(le=3650, ge=1)
    crew: list[CrewMember] = Field(max_length=12, min_length=1)
    mission_status: str = Field(default="planned")
    budget_millions: float = Field(ge=1.0, le=10000.0)

    @model_validator(mode="after")
    def check_mission_id(self) -> Self:
        if len(self.mission_id) < 1 or self.mission_id[0] != "M":
            raise Exception("Mission ID must start with \"M\"")
        return self

    @model_validator(mode="after")
    def check_high_rank(self) -> Self:
        has_high_rank = False
        for member in self.crew:
            if member.rank == Rank.CAPTAIN or member.rank == Rank.COMMANDER:
                has_high_rank = True
        if not has_high_rank:
            raise Exception("Must have at least one Commander or Captain")
        return self

    @model_validator(mode="after")
    def check_appropriate_crew(self) -> Self:
        if self.duration_days > 365:
            for member in self.crew:
                if member.years_experience < 5:
                    raise Exception("Long missions (> 365 days) need 50% "
                                    "experienced crew (5+ years)")
        return self

    @model_validator(mode="after")
    def check_all_are_active(self) -> Self:
        for member in self.crew:
            if not member.is_active:
                raise Exception("All crew members must be active")
        return self
    pass


space_mission = SpaceMission(
    mission_id="M2024_MARS",
    mission_name="Mars Colony Establishment",
    destination="Mars",
    launch_date=datetime(2020, 2, 2),
    duration_days=900,
    crew=[
        CrewMember(
            member_id="123",
            name="Sarah Connor",
            rank=Rank.COMMANDER,
            age=18,
            specialization="Mission Command",
            years_experience=5,
            is_active=True
        ),
        CrewMember(
            member_id="123",
            name="John Smith",
            rank=Rank.LIEUTENANT,
            age=18,
            specialization="Navigation",
            years_experience=5,
            is_active=True
        ),
        CrewMember(
            member_id="123",
            name="Alice Johnson",
            rank=Rank.OFFICER,
            age=18,
            specialization="Engineering",
            years_experience=5,
            is_active=True
        )
    ],
    budget_millions=2500.0
)

print(f"""Space Mission Crew Validation
=========================================
Valid mission created:
Mission: {space_mission.mission_name}
ID: {space_mission.mission_id}
Destination: {space_mission.destination}
Duration: {space_mission.duration_days}
Budget: ${space_mission.budget_millions}M
Crew size: {len([member for member in space_mission.crew])}
Crew members:""")
[print(f"- {member.name} ({member.rank.name.lower()}) - {member.specialization}")
 for member in space_mission.crew]

try:
    SpaceMission(
        mission_id="M2024_MARS",
        mission_name="Mars Colony Establishment",
        destination="Mars",
        launch_date=datetime(2020, 2, 2),
        duration_days=900,
        crew=[
            CrewMember(
                member_id="123",
                name="Sarah Connor",
                rank=Rank.OFFICER,
                age=18,
                specialization="Mission Command",
                years_experience=5,
                is_active=True
            ),
            CrewMember(
                member_id="123",
                name="John Smith",
                rank=Rank.LIEUTENANT,
                age=18,
                specialization="Navigation",
                years_experience=5,
                is_active=True
            ),
            CrewMember(
                member_id="123",
                name="Alice Johnson",
                rank=Rank.OFFICER,
                age=18,
                specialization="Engineering",
                years_experience=5,
                is_active=True
            )
        ],
        budget_millions=2500.0
    )
except Exception as err:
    print(f"""

=========================================
Expected validation error:
{err}""")
