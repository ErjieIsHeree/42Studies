from enum import Enum
from pydantic import BaseModel, Field, model_validator
from datetime import datetime
from typing_extensions import Self


class ContactType(Enum):
    RADIO = "radio"
    VISUAL = "visual"
    PHYSICAL = "physical"
    TELEPATHIC = "telepathic"
    pass


class AlienContact(BaseModel):
    contact_id: str = Field(max_length=15, min_length=5)
    timestamp: datetime
    location: str = Field(max_length=100, min_length=3)
    contact_type: ContactType
    signal_strength: float = Field(ge=0.0, le=10.0)
    duration_minutes: int = Field(ge=1, le=1440)
    witness_count: int = Field(ge=1, le=100)
    message_received: str = Field(default="", max_length=500)
    is_verified: bool = Field(default=False)

    @model_validator(mode='after')
    def check_contact_id(self) -> Self:
        if (len(self.contact_id) < 2 or self.contact_id[0] != "A" or
           self.contact_id[1] != "C"):
            raise Exception("Contact ID must start with \"AC\" "
                            "(Alien Contact)")
        return self

    @model_validator(mode='after')
    def check_physical_contact(self) -> Self:
        if self.contact_type == ContactType.PHYSICAL and not self.is_verified:
            raise Exception("Physical contact reports must be verified")
        return self

    @model_validator(mode='after')
    def check_telepathic_contact(self) -> Self:
        if (self.contact_type == ContactType.TELEPATHIC and
           self.witness_count < 3):
            raise Exception("Telepathic contact requires at least 3 witnesses")
        return self

    @model_validator(mode='after')
    def check_strong_signal(self) -> Self:
        if self.signal_strength > 7.0 and self.message_received == "":
            raise Exception("Strong signals (> 7.0) should include received "
                            "messages")
        return self
    pass


alien_contact = AlienContact(
    contact_id="AC_2024_001",
    timestamp=datetime(2020, 2, 2),
    location="Area 51, Nevada",
    contact_type=ContactType.RADIO,
    signal_strength=8.5,
    duration_minutes=45,
    witness_count=5,
    message_received="Greetings from Zeta Reticuli",
    is_verified=True
)

print(f"""Alien Contact Log Validation
======================================
Valid contact report:
ID: {alien_contact.contact_id}
Type: {alien_contact.contact_type.value}
Location: {alien_contact.location}
Signal: {alien_contact.signal_strength}/10
Duration: {alien_contact.duration_minutes} minutes
Witnesses: {alien_contact.witness_count}
Message: '{alien_contact.message_received}'
""")

try:
    AlienContact(
        contact_id="AC_2024_001",
        timestamp=datetime(2020, 2, 2),
        location="Area 51, Nevada",
        contact_type=ContactType.TELEPATHIC,
        signal_strength=8.5,
        duration_minutes=45,
        witness_count=2,
        message_received="Greetings from Zeta Reticuli",
        is_verified=True
    )
except Exception as err:
    print(f"""======================================
Expected validation error:
{err}""")
