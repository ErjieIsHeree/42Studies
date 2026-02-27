class SecurePlant():
    """A blueprint for creating a plant"""

    def __init__(self, name: str) -> None:
        """The class plant instance an object Plant"""
        print(f"Plant created: {name.capitalize()}")
        self.name = name
        self.__height = 0
        self.__age = 0

    def set_height(self, height: int) -> None:
        """Set the height of the plant"""
        if (height >= 0):
            print(f"Height updated: {height}cm [OK]")
            self.__height = height
        else:
            print(f"Invalid operation attempted: height {height}cm [REJECTED]")
            print("Security: Negative height rejected")

    def set_age(self, age: int) -> None:
        """Set the age of the plant"""
        if (age >= 0):
            print(f"Age updated: {age} days [OK]")
            self.__age = age
        else:
            print(f"Invalid operation attempted: age {age} days [REJECTED]")
            print("Security: Negative age rejected")

    def get_height(self) -> int:
        """Get the age of the plant"""
        return self.__height

    def get_age(self) -> int:
        """Get the age of the plant"""
        return self.__age


def get_info(p: SecurePlant) -> None:
    """Get the information of a Secure Plant"""
    print(f"Current plant: {p.name.capitalize()} ({p.get_height()}", end="")
    print(f"cm, {p.get_age()} days)")


rose = SecurePlant("Rose")
rose.set_height(25)
rose.set_age(30)
print()
rose.set_height(-5)
print()
get_info(rose)
