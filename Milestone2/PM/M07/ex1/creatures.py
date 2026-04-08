from .abs_capabilities import HealCapability, TransformCapability
from ex0.creatures import Creature


class Sproutling(Creature, HealCapability):
    def __init__(self):
        super().__init__("Sproutling", "Grass")

    def attack(self) -> str:
        return "Sproutling uses Vine Whip!"

    def heal(self) -> str:
        return "Sproutling heals itself for a small amount"
    pass


class Bloomelle(Creature, HealCapability):
    def __init__(self):
        super().__init__("Bloomelle", "Grass/Fairy")

    def attack(self) -> str:
        return "Bloomelle uses Petal Dance!"

    def heal(self) -> str:
        return "Bloomelle heals itself and others for a large amount"
    pass


class Shiftling(Creature, TransformCapability):
    def __init__(self) -> None:
        super().__init__("Shiftling", "Normal")
        self.shapeshifted: bool = False
        return

    def attack(self) -> str:
        if self.shapeshifted:
            return "Shiftling performs a boosted strike!"
        else:
            return "Shiftling attacks normally."

    def transform(self) -> str:
        self.shapeshifted = True
        return "Shiftling shifts into a sharper form!"

    def revert(self) -> str:
        self.shapeshifted = False
        return "Shiftling returns to normal."
    pass


class Morphagon(Creature, TransformCapability):
    def __init__(self) -> None:
        super().__init__("Morphagon", "Normal/Dragon")
        self.shapeshifted: bool = False
        return

    def attack(self) -> str:
        if self.shapeshifted:
            return "Morphagon unleashes a devastating morph strike!"
        else:
            return "Morphagon attacks normally."

    def transform(self) -> str:
        self.shapeshifted = True
        return "Morphagon morphs into a dragonic battle form!"

    def revert(self) -> str:
        self.shapeshifted = False
        return "Morphagon stabilizes its form."
    pass
