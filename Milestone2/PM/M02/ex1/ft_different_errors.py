def garden_operations() -> None:
    valueErrorTest: str = "abc"
    zeroDivisionErrorTest: int = 0
    fileNotFoundErrorTest: str = "missing.txt"
    keyErrorTest: str = r"missing\_plant"

    print("\nTesting ValueError...")
    try:
        int(valueErrorTest)
    except ValueError as err:
        print(f"Caught ValueError: {err}")

    print("\nTesting ZeroDivisionError...")
    try:
        5 / zeroDivisionErrorTest
    except ZeroDivisionError as err:
        print(f"Caught ZeroDivisionError: {err}")

    print("\nTesting FileNotFoundError...")
    try:
        open(fileNotFoundErrorTest)
    except FileNotFoundError:
        print("Caught FileNotFoundError: No such file "
              f"'{fileNotFoundErrorTest}'")

    print("\nTesting KeyError...")

    try:
        dict = {
            "Hello": "A word",
            "Goodbye": "Another word"
            }
        dict[keyErrorTest]
    except KeyError:
        print(f"Caught KeyError: '{keyErrorTest}'")
    pass


def test_error_types() -> None:
    print("Testing multiple errors together...")
    valueErrorTest: str = "123"
    zeroDivisionErrorTest: int = 0
    fileNotFoundErrorTest: str = "missing.txt"
    keyErrorTest: str = r"missing\_plant"

    try:
        int(valueErrorTest)
        5 / zeroDivisionErrorTest
        open(fileNotFoundErrorTest)
        dict = {
            "Hello": "A word",
            "Goodbye": "Another word"
            }
        dict[keyErrorTest]
    except Exception:
        print("Caught an error, but program continues!")
    pass


print("=== Garden Error Types Demo ===")
garden_operations()
print()
test_error_types()
print("\nAll error types tested successfully!")
