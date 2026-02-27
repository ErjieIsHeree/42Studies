class Plant():
    """A blueprint for creating a plant"""

    def __init__(self, name: str, height: int, age: int) -> None:
        """The class plant instance an object Plant"""
        self.name = name
        self.height = height
        self.p_age = age

    def grow(self) -> None:
        """This method adds more heigth to the actual plant"""
        self.height += 1

    def age(self) -> None:
        """This method adds 1 to the age of the plant"""
        self.p_age += 1


def get_info(p: Plant) -> None:
    """Use this function to get the information of a plant"""
    print(f"{p.name.capitalize()}: {p.height}cm, {p.p_age} days old")


def week_growth_simulation(plant_l: list[Plant]) -> None:
    """Use this function to simulate a week of grow for a list of plants"""
    print("=== Day 1 ===")
    for p in plant_l:
        get_info(p)
    i = 0
    while i < 6:
        for p in plant_l:
            p.age()
            p.grow()
        i += 1
    print("=== Day 7 ===")
    for p in plant_l:
        get_info(p)
        print("Growth this week: +6cm")
        i += 1


week_growth_simulation([
        Plant("Rose", 25, 30)
    ])
