from .abs_battel_strat import BattleStrategy
from ex0.abs_creature import Creature
from ex1.abs_capabilities import HealCapability, TransformCapability


class NormalStrategy(BattleStrategy):
    def act(self, creature: Creature) -> None:
        print(creature.attack())
        return

    def is_valid(self, creature: Creature) -> bool:
        return True
    pass


class AggressiveStrategy(BattleStrategy):
    def act(self, creature: Creature) -> None:
        if isinstance(creature, TransformCapability):
            print(creature.transform())
            print(creature.attack())
            print(creature.revert())
        else:
            raise ValueError(f"Invalid Creature '{creature.name}' for this agg"
                             "ressive strategy")
        return

    def is_valid(self, creature: Creature) -> bool:
        if isinstance(creature, TransformCapability):
            return True
        return False
    pass


class DefensiveStrategy(BattleStrategy):
    def act(self, creature: Creature) -> None:
        if isinstance(creature, HealCapability):
            print(creature.attack())
            print(creature.heal())
        else:
            raise ValueError(f"Invalid Creature '{creature.name}' for this def"
                             "ensive strategy")
        return

    def is_valid(self, creature: Creature) -> bool:
        if isinstance(creature, HealCapability):
            return True
        return False
    pass
