class Plant():
    """A blueprint for creating a plant"""

    def __init__(self, name: str, height: int, age: int) -> None:
        """The class plant instance an object Plant"""
        self.name = name
        self.height = height
        self.age = age


plant_l = [
    Plant("Rose", 25, 30),
    Plant("Oak", 200, 365),
    Plant("Cactus", 5, 90),
    Plant("Sunflower", 80, 45),
    Plant("Fern", 15, 120)
]

print("=== Plant Factory Output ===")
for p in plant_l:
    print(f"Created: {p.name.capitalize()} ({p.height}cm, {p.age} days)")

total = 0
for p in plant_l:
    total += 1

print()
print(f"Total plants created: {total}")
