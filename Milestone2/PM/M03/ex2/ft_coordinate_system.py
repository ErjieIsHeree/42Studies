
import math
import sys

point_zero: tuple = (0, 0, 0)
coordinates: tuple = (10, 20, 5)
distance: float
argc: int = len(sys.argv)


def calculate_distance() -> float:
    return math.sqrt((point_zero[0] - coordinates[0]) ** 2 +
                     (point_zero[1] - coordinates[1]) ** 2 +
                     (point_zero[2] - coordinates[2]) ** 2)


def print_solution() -> None:
    distance = calculate_distance()
    print(f"Position created: {coordinates}")
    print(f"Distance between {point_zero} and {coordinates}: {distance}\n")


if argc == 1:
    print("=== Game Coordinate System ===\n")
    print_solution()
elif argc == 2:
    print("=== Game Coordinate System ===\n")
    arg: str = sys.argv[1]
    number: str = ""
    coordinates = ()
    parseable: bool = True
    coordinate_qty: int = 0

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
            raise Exception
    except ValueError as err:
        print(f"Parsing invalid coordinates: \"{arg}\"")
        print(f"Error parsing coordinates: {err}")
        print(f"Error details - Type: {err.__str__}, Args: ({err})")
    except Exception:
        print("Dude, just enter 3 correct numbers between commas")
    else:
        print(f"Parsing coordinates: \"{arg}\"")
        print_solution()
else:
    print("Subject didn't show any solution to more than 1 argument.")
