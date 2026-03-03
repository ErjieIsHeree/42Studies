class GardenManager():
    __plant_list: list[list] = []

    def add_plant(self, plant_name: str | None, water_level: int,
                  sunlight_hours: int) -> None:
        try:
            if plant_name is None:
                raise self.PlantNamingError
            self.__plant_list.append([plant_name, water_level, sunlight_hours])
            print(f"Added {plant_name} successfully")
        except self.PlantNamingError as err:
            print(f"Error adding plant: {err}")
        pass

    def water_plants(self) -> None:
        print("Opening watering system")
        try:
            for plant in self.__plant_list:
                if plant[0] is not None:
                    print(f"Watering {plant[0]} - success")
                else:
                    raise Exception
        except Exception:
            print("Error: Cannot water None - invalid plant!")
        finally:
            print("Closing watering system (cleanup)")

    def check_plant_health(self) -> str | None:
        for plant in self.__plant_list:
            try:
                if plant[1] < 1:
                    raise ValueError(f"Water level {plant[1]} is too low "
                                     "(min 1)")
                elif plant[1] > 10:
                    raise ValueError(f"Water level {plant[1]} is too high "
                                     "(max 10)")
                elif plant[2] < 2:
                    raise ValueError(f"Sunlight hours {plant[2]} is too low "
                                     "(min 2)")
                elif plant[2] > 12:
                    raise ValueError(f"Sunlight hours {plant[2]} is too high "
                                     "(max 12)")
                print(f"{plant[0]}: healthy (water: {plant[1]}, sun: "
                      f"{plant[2]})")
            except ValueError as err:
                print(f"Error checking {plant[0]}: {err}")
    pass

    class GardenError(Exception):
        pass

    class PlantNamingError(GardenError):
        def __str__(self) -> str:
            return "Plant name cannot be empty!"
        pass

    class WaterError(GardenError):
        def __str__(self) -> str:
            return "Not enough water in tank"
        pass
    pass


def test_garden_management() -> None:
    garden_manager: GardenManager = GardenManager()

    print("=== Garden Management System ===")

    print("\nAdding plants to garden...")
    garden_manager.add_plant("tomato", 5, 8)
    garden_manager.add_plant("lettuce", 15, 8)
    garden_manager.add_plant(None, 5, 8)

    print("\nWatering plants...")
    garden_manager.water_plants()

    print("\nChecking plant health...")
    garden_manager.check_plant_health()

    print("\nTesting error recovery...")
    try:
        raise garden_manager.WaterError
    except garden_manager.GardenError as err:
        print(f"Caught GardenError: {err}")
    print("System recovered and continuing...")

    print("\nGarden management system test complete!")
    pass


test_garden_management()
