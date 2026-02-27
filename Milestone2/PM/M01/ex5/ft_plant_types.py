class Plant():
    """A blueprint for creating a plant"""

    def __init__(self, name: str, height: int, age: int) -> None:
        """The class plant instance an object Plant"""
        self.name = name
        self.height = height
        self.age = age


class Flower(Plant):
    """A blueprint for creating a flower"""
    def __init__(self, name: str, height: int, age: int, color: str | None,
                 ability: bool) -> None:
        super().__init__(name, height, age)
        self.color = color
        self.ability = ability

    def bloom(self) -> None:
        """This method makes the flower blooming if it color has a string
        and ability is set to true"""
        if self.color and self.ability:
            print(f"{self.name.capitalize()} is blooming beautifully!")


class Tree(Plant):
    """A blueprint for creating a tree"""
    def __init__(self, name: str, height: int, age: int, trunk_diameter: int,
                 ability: bool) -> None:
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter
        self.ability = ability

    def produce_shade(self) -> None:
        """This method makes the tree to produce shade if it has diameter
        different of 0 and has ability set to true"""
        if self.trunk_diameter and self.ability:
            print(f"{self.name.capitalize()} provides 78 square ", end="")
            print("meters of shade")


class Vegetable(Plant):
    """A blueprint for creating a vegetable"""
    def __init__(self, name: str, height: int, age: int, harvest_season: str,
                 nutritional_value: str):
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value


def get_info(plant: Flower | Tree | Vegetable) -> None:
    """Use this function to get information of a plant"""
    if isinstance(plant, Flower):
        get_flower_info(plant)
    elif isinstance(plant, Tree):
        get_tree_info(plant)
    elif isinstance(plant, Vegetable):
        get_vegetable_info(plant)


def get_flower_info(flower: Flower) -> None:
    """Use this function to get information of a flower"""
    print(f"{flower.name.capitalize()} (Flower): {flower.height}", end="")
    print(f"cm, {flower.age} days, {flower.color} color")


def get_tree_info(tree: Tree) -> None:
    """Use this function to get information of a tree"""
    print(f"{tree.name.capitalize()} (Tree): {tree.height}", end="")
    print(f"cm, {tree.age} days, {tree.trunk_diameter}cm diameter")


def get_vegetable_info(vegetable: Vegetable) -> None:
    """Use this function to get information of a vegetable"""
    print(f"{vegetable.name.capitalize()} (Vegetable): ", end="")
    print(f"{vegetable.height}cm, {vegetable.age} days, ", end="")
    print(f"{vegetable.harvest_season} harvest")


plant_l = [
        Flower("rose", 25, 30, "red", True),
        Tree("oak", 2130, 1850, 50, True),
        Vegetable("tomato", 80, 90, "summer", "C")
    ]

print("=== Garden Plant Types ===", end="\n\n")

get_info(plant_l[0])
plant_l[0].bloom()
print()

get_info(plant_l[1])
plant_l[1].produce_shade()

print()

get_info(plant_l[2])
print(f"Tomato is rich in vitamin {plant_l[2].nutritional_value}")
