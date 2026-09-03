from .hub import Hub
from .connection import Connection


class Drone:
    number: int
    location: Hub | Connection
