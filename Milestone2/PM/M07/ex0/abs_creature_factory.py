import abc
from .abs_creature import Creature


class CreatureFactory(abc.ABC):
    @abc.abstractmethod
    def create_base(self) -> Creature: ...

    @abc.abstractmethod
    def create_evolved(self) -> Creature: ...
    pass
