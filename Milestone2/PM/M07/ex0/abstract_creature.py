import abc


class Creature(abc.ABC):
    def __init__(self, name: str, type: str):
        self.name: str = name
        self.type: str = type

    @abc.abstractmethod
    def attack(self) -> str: ...

    def describe(self) -> str:
        return (f"{self.name.capitalize()} is a {self.type.capitalize()} type "
                "Creature")
    pass
