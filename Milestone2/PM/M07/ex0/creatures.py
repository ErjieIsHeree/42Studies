from .abs_creature import Creature


class Flameling(Creature):
    def __init__(self):
        super().__init__("Flameling", "Fire")

    def attack(self) -> str:
        return "Flameling uses Ember!"
    pass


class Pyrodon(Creature):
    def __init__(self):
        super().__init__("Pyrodon", "Fire/Flying")

    def attack(self) -> str:
        return "Pyrodon uses Flamethrower!"
    pass


class Aquabub(Creature):
    def __init__(self):
        super().__init__("Aquabub", "Water")

    def attack(self) -> str:
        return "Aquabub uses Water Gun!"
    pass


class Torragon(Creature):
    def __init__(self):
        super().__init__("Torragon", "Water")

    def attack(self) -> str:
        return "Torragon uses Hydro Pump!"
    pass
