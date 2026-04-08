import abc
from ex0.abs_creature import Creature


class BattleStrategy(abc.ABC):
    @abc.abstractmethod
    def act(self, creature: Creature) -> None: ...

    @abc.abstractmethod
    def is_valid(self, creature: Creature) -> bool: ...
    pass
