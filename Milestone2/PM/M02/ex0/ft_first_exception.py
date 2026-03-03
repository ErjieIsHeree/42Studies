def check_temperature(temp_str: str) -> int | None:
    temp_int: int = 0

    try:
        temp_int = int(temp_str)
    except ValueError:
        print(f"Error: '{temp_str}' is not a valid number")
    else:
        if (temp_int > 40):
            print(f"Error: {temp_int}ºC is too hot for plants (max 40ºC)")
        elif (temp_int < 0):
            print(f"Error: {temp_int}ºC is too cold for plants (min 0ºC)")
        else:
            print(f"Temperature {temp_int}ºC is perfect for plants!")
            return temp_int
    return None


def test_temperature_input():
    test_a: str = "25"
    test_b: str = "abc"
    test_c: str = "100"
    test_d: str = "-50"

    print(f"\nTesting temperature: {test_a}")
    check_temperature(test_a)

    print(f"\nTesting temperature: {test_b}")
    check_temperature(test_b)

    print(f"\nTesting temperature: {test_c}")
    check_temperature(test_c)

    print(f"\nTesting temperature: {test_d}")
    check_temperature(test_d)

    print("\nAll tests completed - program didn't crash!")


print("=== Garden Temperature Checker ===")
test_temperature_input()
