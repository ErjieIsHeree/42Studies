class Plant():
    """A blueprint for creating a plant"""
    def __init__(self, name: str, height: int) -> None:
        """The class plant instance an object Plant"""
        self.name = name
        self.height = height


class FloweringPlant(Plant):
    """A blueprint for creating a flowering plant"""
    def __init__(self, name: str, height: int, color: str,
                 ability: bool):
        """The class plant instance an object flowering"""
        super().__init__(name, height)
        self.color = color
        self.ability = ability

    def is_blooming(self):
        if self.color and self.ability:
            return True
        return False


class PrizeFlower(FloweringPlant):
    """A blueprint for creating a prize flower"""
    def __init__(self, name: str, height: int, color: str,
                 ability: bool, prize: int):
        """The class plant instance an object prize flower"""
        super().__init__(name, height, color, ability)
        self.prize = prize


def get_plant_info(p: Plant) -> None:
    """Use this function to get information of a Plant"""
    print(f"{p.name.capitalize()}: {p.height}cm")


def get_floweringplant_info(fp: FloweringPlant) -> None:
    """Use this function to get information of a Flowering Plant"""
    if fp.is_blooming():
        blooming = "blooming"
    else:
        blooming = "not blooming"
    print(f"{fp.name.capitalize()}: {fp.height}cm, ({blooming})")


def get_prizeflower_info(pf: PrizeFlower) -> None:
    """Use this function to get information of a Flowering Plant"""
    if pf.is_blooming():
        blooming = "blooming"
    else:
        blooming = "not blooming"
    print(f"{pf.name.capitalize()}: {pf.height}cm, ({blooming})")


class Garden():
    def __init__(self, name: str, plant_l: list[Plant]):
        self.name = name
        self.plant_l = plant_l


class GardenManager():
    garden: Plant = []

    @staticmethod
    def create_garden_network(self) -> Garden:
        garden += [Plant("Rose", 25)]

    class GardenStats():
        @staticmethod
        def get_info() -> None:
            print("=== Garden Managment System Demo ===")
            print()


a = Plant("Rose", 20, 40)

if a is Plant:
    print("a")
