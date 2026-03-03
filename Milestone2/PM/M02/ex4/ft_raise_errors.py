def check_plant_health(plant_name: str | None, water_level: int,
                       sunlight_hours: int) -> str | None:
    if plant_name is None:
        raise ValueError("Plant name cannot be empty!")
    elif water_level < 1:
        raise ValueError(f"Water level {water_level} is too low (min 1)")
    elif water_level > 10:
        raise ValueError(f"Water level {water_level} is too high (max 10)")
    elif sunlight_hours < 2:
        raise ValueError(f"Sunlight hours {sunlight_hours} is too low (min 2)")
    elif sunlight_hours > 12:
        raise ValueError(f"Sunlight hours {sunlight_hours} is too high "
                         "(max 12)")
    return f"Plant '{plant_name}' is healthy!"


def test_plant_checks() -> None:
    print("=== Garden Plant Health Checker ===")

    print("\nTesting good values...")
    print(check_plant_health("tomato", 5, 5))

    print("\nTesting empty plant name...")
    try:
        check_plant_health(None, 5, 5)
    except Exception as err:
        print(f"Error: {err}")

    print("\nTesting bad water level...")
    try:
        check_plant_health("tomato", 15, 5)
    except Exception as err:
        print(f"Error: {err}")

    print("\nTesting bad sunlight hours...")
    try:
        check_plant_health("tomato", 5, 0)
    except Exception as err:
        print(f"Error: {err}")

    print("\nAll error raising tests completed!")
    pass


test_plant_checks()
