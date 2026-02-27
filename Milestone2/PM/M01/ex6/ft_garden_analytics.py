class Plant():
    """A blueprint for creating a plant"""
    name: str = ""
    __height: int = 0
    total_growth: int = 0
    __type: str = "Plant"

    def __init__(self, name: str, height: int) -> None:
        """Use this to create a new object plant"""
        self.name = name
        if height > 0:
            self.__height = height
        pass

    def get_height(self) -> int:
        return self.__height

    def grow(self) -> None:
        """Adds the height of the plant by 1 and print it"""
        self.__height += 1
        self.total_growth += 1
        print(f"{self.name} grew 1cm")
        pass

    def get_plant_score(self) -> int:
        """Use this function to get score of the plant"""
        return self.__height

    def get_plant_info(self, final: bool) -> None:
        """Use this function to get information of a Flowering Plant"""
        if final:
            print(f"- {self.name}: {self.__height}cm")
        else:
            print(f"- {self.name}: {self.__height}cm", end="")
        pass

    def get_type(self) -> str:
        """
        Get the type of the actual plant, flowering plant or prize flower.
        Returns:
            int: (0 - plant) (1 - flowering plant) (2 - prize plant)
        """
        return self.__type


class FloweringPlant(Plant):
    """A blueprint for creating a flowering plant"""
    color: str = "as"
    ability: bool = False

    def __init__(self, name: str, height: int, color: str,
                 ability: bool):
        """Use this to create a new object flowering plant"""
        super().__init__(name, height)
        self.color = color
        self.ability = ability
        self.__type = "FloweringPlant"
        pass

    def is_blooming(self) -> bool:
        """Use this method to check if the flowering plant is blooming"""
        if self.color and self.ability:
            return True
        return False

    def get_flowering_plant_info(self, final: bool) -> None:
        """Use this function to get information of a Flowering Plant"""
        if self.is_blooming():
            blooming = "blooming"
        else:
            blooming = "not blooming"
        if final:
            self.get_plant_info(False)
            print(f", {self.color} flowers ({blooming})")
        else:
            self.get_plant_info(False)
            print(f", {self.color} flowers ({blooming})", end="")
        pass

    def get_flowering_plant_score(self) -> int:
        """Use this function to get score of the flowering plant"""
        total_score: int = self.get_plant_score()
        if self.is_blooming:
            total_score += 10
        return total_score

    def get_type(self) -> str:
        """
        Get the type of the actual plant, flowering plant or prize flower.
        Returns:
            int: (0 - plant) (1 - flowering plant) (2 - prize plant)
        """
        return self.__type


class PrizeFlower(FloweringPlant):
    """A blueprint for creating a prize flower"""
    prize: int = 0

    def __init__(self, name: str, height: int, color: str,
                 ability: bool, prize: int):
        """Use this to create a new object prize flower"""
        super().__init__(name, height, color, ability)
        self.prize = prize
        self.__type = "PrizePlant"
        pass

    def get_prize_flower_info(self) -> None:
        """Use this function to get information of a Flowering Plant"""
        self.get_flowering_plant_info(False)
        print(f", Prize points: {self.prize}")
        pass

    def get_prize_plant_score(self) -> int:
        """Use this function to get score of the flowering plant"""
        total_score: int = self.get_flowering_plant_score()
        total_score += (self.prize * 2)
        return total_score

    def get_type(self) -> str:
        """
        Get the type of the actual plant, flowering plant or prize flower.
        Returns:
            int: (0 - plant) (1 - flowering plant) (2 - prize plant)
        """
        return self.__type


class Garden():
    """This blueprint is used to create Gardens"""
    owner: str = ""
    plants: list = []

    def __init__(self, owner: str, plants: list):
        """Use this to create a new object Garden"""
        self.owner = owner
        self.plants = plants
        pass

    def grow_all(self) -> None:
        """Use this function to make all plants in the garden grow 1 time"""
        for p in self.plants:
            p.grow()

    def add_plant(self, plant: Plant) -> None:
        """This method is used to add plants"""
        self.plants += [plant]
        print(f"Added {plant.name} to {self.owner.capitalize()}'s"
              " garden")
        pass


class GardenManager():
    """This class is used to manage gardens"""
    gardens: list[Garden] = []

    def create_garden_network(self) -> None:
        """Use this method to create a garden network (it will delete the
        actual plants in the garden)"""
        print("=== Garden Management System Demo ===\n")
        self.gardens.append(Garden("Alice", []))
        Garden.add_plant(self.gardens[0], Plant("Oak Tree", 100))
        Garden.add_plant(self.gardens[0], FloweringPlant("Rose", 25, "red",
                                                         True))
        Garden.add_plant(self.gardens[0], PrizeFlower("Sunflower", 50,
                                                      "yellow", True, 10))
        print("\nAlice is helping all plants grow...")
        self.gardens[0].grow_all()
        print()
        self.gardens.append(Garden("Bob", []))
        self.gardens[1].plants += [PrizeFlower("Sunflower", 80, "yellow", True,
                                               1)]
        pass

    class GardenStats():
        def get_garden_info(self, garden: Garden) -> None:
            """Use this function to get the info of a garden"""
            print(f"=== {garden.owner.capitalize()}'s Garden Report ===")
            print("Plants in garden:")
            self.__print_plants_info(garden.plants)
            print()
            print("Plants added: ", end="")
            self.__print_plants_total_added(garden.plants)
            print(", Total growth: ", end="")
            self.__print_plants_total_growth(garden.plants)
            self.__print_total_plant_types(garden.plants)
            pass

        @staticmethod
        def __print_plants_info(plants: list) -> None:
            """Use this function to print information of a Plant"""
            for plant in plants:
                if plant.get_type() == "Plant":
                    Plant.get_plant_info(plant, True)
                elif plant.get_type() == "FloweringPlant":
                    FloweringPlant.get_flowering_plant_info(plant, True)
                elif plant.get_type() == "PrizePlant":
                    PrizeFlower.get_prize_flower_info(plant)
            pass

        @staticmethod
        def __print_plants_total_added(plants: list) -> None:
            """Use this function to print the total plants added"""
            total_plants: int = 0
            for plant in plants:
                total_plants += 1
            print(f"{total_plants}", end="")
            pass

        @staticmethod
        def __print_plants_total_growth(plants: list) -> None:
            """Use this function to print the total growth height of plants"""
            garden_total_growth: int = 0
            for plant in plants:
                garden_total_growth += plant.total_growth
            print(f"{garden_total_growth}cm")
            pass

        @staticmethod
        def __print_total_plant_types(plants: list) -> None:
            """Use this function to print amount of each type of plant"""
            regular: int = 0
            flowering: int = 0
            prize: int = 0
            for plant in plants:
                if plant.get_type() == "Plant":
                    regular += 1
                elif plant.get_type() == "FloweringPlant":
                    flowering += 1
                elif plant.get_type() == "PrizePlant":
                    prize += 1
            print(f"Plant types: {regular} regular, {flowering} flowering, "
                  f"{prize} prize flowers")
            pass

        def print_garden_scores(self, gardens: list[Garden]) -> None:
            """Use this function to print gardens scores"""
            print("Garden scores - ", end="")
            total_gardens: int = 0
            i: int = 1
            for garden in gardens:
                total_gardens += 1
            for garden in gardens:
                print(f"{garden.owner.capitalize()}: "
                      f"{self.get_garden_score(garden)}", end="")
                if i < total_gardens:
                    print(", ", end="")
                    i += 1
            print()

        @staticmethod
        def get_garden_score(garden: Garden) -> int:
            """This method will print the total score of a garden"""
            garden_score: int = 0
            for plant in garden.plants:
                if plant.get_type() == "Plant":
                    garden_score += plant.get_plant_score()
                elif plant.get_type() == "FloweringPlant":
                    garden_score += plant.get_flowering_plant_score()
                elif plant.get_type() == "PrizePlant":
                    garden_score += plant.get_prize_plant_score()
            return garden_score

        @staticmethod
        def print_total_garden(gardens: list[Garden]) -> None:
            """This method will print the total number of gardens managed"""
            total_gardens: int = 0
            for garden in gardens:
                total_gardens += 1
            print(f"Total gardens managed: {total_gardens}")
            pass


def height_validation_checker(plant: Plant) -> bool:
    if plant.get_height() < 0:
        return False
    return True


if __name__ == "__main__":
    garden_manager = GardenManager()
    garden_stats = garden_manager.GardenStats()

    garden_manager.create_garden_network()
    garden_stats.get_garden_info(garden_manager.gardens[0])
    print()
    plant = Plant("Rose", -5)
    print(f"Height validation test: {height_validation_checker(plant)}")
    garden_stats.print_garden_scores(garden_manager.gardens)
    garden_stats.print_total_garden(garden_manager.gardens)
