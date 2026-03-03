def water_plants(plant_list: list[str]) -> None:
    print("Opening watering system")
    try:
        for plant in plant_list:
            if plant is not None:
                print(f"Watering {plant}")
            else:
                raise Exception
    except Exception:
        print("Error: Cannot water None - invalid plant!")
    finally:
        print("Closing watering system (cleanup)")
    pass


def test_watering_system() -> None:
    good_plant_list = ["tomato", "lettuce", "carrots"]
    bad_plant_list = ["tomato", None, "carrots"]

    print("=== Garden Watering System ===")

    print("\nTesting normal watering...")
    water_plants(good_plant_list)
    print("Watering completed successfully!")

    print("\nTesting with error...")
    water_plants(bad_plant_list)

    print("\nCleanup always happens, even with errors!")
    pass


test_watering_system()
