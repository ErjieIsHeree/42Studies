class GardenError(Exception):
    pass


class PlantError(GardenError):
    def __str__(self) -> str:
        return "The tomato plant is wilting!"
    pass


class WaterError(GardenError):
    def __str__(self) -> str:
        return "Not enough water in the tank!"
    pass


def test_garde_error() -> None:
    print("=== Custom Garden Errors Demo ===")

    print("\nTesting PlantError...")
    try:
        raise PlantError
    except PlantError as err:
        print(f"Caught PlantError: {err}")

    print("\nTesting PlantError...")
    try:
        raise WaterError
    except WaterError as err:
        print(f"Caught WaterError: {err}")

    print("\nTesting catching all garden errors...")
    try:
        raise PlantError
    except GardenError as err:
        print(f"Caught a garden error: {err}")
    try:
        raise WaterError
    except GardenError as err:
        print(f"Caught a garden error: {err}")

    print("\nAll custom error types work correctly!")


test_garde_error()
