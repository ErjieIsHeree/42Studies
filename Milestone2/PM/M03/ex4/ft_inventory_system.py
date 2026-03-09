
import sys


class InvalidInputException(Exception):
    def __init__(self, message):
        self.message = message
        super().__init__(message)
        pass
    pass


def atoi(s):
    result: int = 0
    number: int = 0

    for c in s:
        if '0' < c > '9':
            raise ValueError(f"{s} is not a valid number")
        elif c == '1':
            number = 1
        elif c == '2':
            number = 2
        elif c == '3':
            number = 3
        elif c == '4':
            number = 4
        elif c == '5':
            number = 5
        elif c == '6':
            number = 6
        elif c == '7':
            number = 7
        elif c == '8':
            number = 8
        elif c == '9':
            number = 9
        result += (result * 10) + number

    return result


argv: list = sys.argv
argc: int = len(argv)
i: int = 1

inventory: dict[str, int] = {}

try:
    while i < argc:
        temp_str: str = ""
        new_key: str = ""
        new_value: int = 0

        for c in argv[i]:
            if c != ":":
                temp_str += c
            else:
                new_key = temp_str
                temp_str = ""
        new_value = atoi(temp_str)
        for key in inventory.keys():
            if key == new_key:
                raise InvalidInputException("Can not introduce same object "
                                            "twice")
        inventory[new_key] = new_value
        i += 1
except InvalidInputException as err:
    print(f"InvalidInputException found: {err}")
except ValueError as err:
    print(f"ValueError found: {err}")
else:
    print("=== Inventory System Analysis ===")
    total_items = 0
    for stock in inventory.values():
        total_items += stock
    print(f"Total items in inventory: {total_items}")
    print(f"Unique item types: {len(inventory)}\n")

    print("=== Current Inventory ===")
    for key, value in inventory.items():
        print(f"{key}: {value} units ({((value / total_items) * 100):.1f}%)")

    print("\n=== Inventory Statistics ===")
    least_abundant: str = ""
    most_abundant: str = ""
    for key, value in inventory.items():
        if least_abundant == "":
            least_abundant = key
            most_abundant = key
        if value < inventory[least_abundant]:
            least_abundant = key
        if value > inventory[most_abundant]:
            most_abundant = key
    print(f"Most abundant: {most_abundant} ({inventory[most_abundant]} units)")
    print(f"Least abundant: {least_abundant} ({inventory[least_abundant]} "
          "unit)\n")
    print("=== Item Categories ===")
    moderate_quantity = {}
    scarce_quantity = {}
    for key, value in inventory.items():
        if value > 4:
            moderate_quantity[key] = value
        else:
            scarce_quantity[key] = value
    print(f"Moderate: {moderate_quantity}")
    print(f"Scarce: {scarce_quantity}\n")

    print("=== Management Suggestions ===")
    print("Restock needed: ", end="")
    first_time = True
    for key, value in inventory.items():
        if (value <= 1):
            if not first_time:
                print(", ", end="")
            print(key, end="")
        first_time = False

    print("\n\n=== Dictionary Properties Demo ===")
    print("Dictionary keys: ", end="")
    first_time = True
    for key in inventory.keys():
        if not first_time:
            print(", ", end="")
        print(key, end="")
        first_time = False
    print("\nDictionary values: ", end="")
    first_time = True
    for values in inventory.values():
        if not first_time:
            print(", ", end="")
        print(values, end="")
        first_time = False
    print("\nSample lookup - 'sword' in inventory: ", end="")
    if "sword" in inventory:
        print(True)
