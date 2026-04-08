from .abstract_creature_factory import CreatureFactory
from .abstract_creature import Creature
from .creatures import Flameling, Pyrodon, Aquabub, Torragon


class FlameFactory(CreatureFactory):
    def create_base(self) -> Creature:
        return Flameling()

    def create_evolved(self) -> Creature:
        return Pyrodon()
    pass


class AquaFactory(CreatureFactory):
    def create_base(self) -> Creature:
        return Aquabub()

    def create_evolved(self) -> Creature:
        return Torragon()
    pass
