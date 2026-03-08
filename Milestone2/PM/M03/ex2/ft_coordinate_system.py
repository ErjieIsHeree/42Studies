
import math

point_zero: tuple = (0, 0, 0)
coordinates: tuple = (10, 20, 5)
distance: float


def calculate_distance() -> float:
    return math.sqrt((point_zero[0] - coordinates[0]) ** 2 +
                     (point_zero[1] - coordinates[1]) ** 2 +
                     (point_zero[2] - coordinates[2]) ** 2)


def print_solution() -> None:
    distance = calculate_distance()
    print(f"Position created: {coordinates}")
    print(f"Distance between {point_zero} and {coordinates}: {distance:.2f}\n")
    pass


def demostration_unpack() -> None:
    print("Unpacking demonstration:")
    x, y, z = coordinates
    print(f"Player at x={x}, y={y}, z={z}")
    print(f"Coordinates: X={x}, Y={y}, Z={z}")
    pass


print("=== Game Coordinate System ===\n")
print_solution()

arg: str = "3,4,0"
number: str = ""
coordinates = ()
coordinate_qty: int = 0

print(f"Parsing coordinates: \"{arg}\"")
for c in arg:
    if c != ',':
        number += c
    else:
        coordinates = coordinates + tuple([int(number)])
        number = ""
coordinates = coordinates + tuple([int(number)])
print_solution()

number = ""
arg = "abc,def,ghi"
print(f"Parsing invalid coordinates: \"{arg}\"")
try:
    for c in arg:
        if c != ',':
            number += c
        else:
            coordinates = coordinates + tuple([int(number)])
            number = ""
    coordinates = coordinates + tuple([int(number)])
    for i in coordinates:
        coordinate_qty += 1
    if coordinate_qty != 3:
        raise ValueError("Coordinates have 3 values: x, y, z")
except ValueError as err:
    print(f"Error parsing coordinates: {err}")
    print(f"Error details - Type: {err.__class__.__name__}, Args: (", end="")
    for arg in err.args:
        print(f"\"{arg}\",", end="")
    print(")")
except Exception:
    print("Dude, just enter 3 correct numbers between commas")
print()

coordinates = (3, 4, 0)
demostration_unpack()
