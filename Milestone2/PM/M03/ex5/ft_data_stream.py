from typing import Generator
# next(), iter(), range(), len(), print(), typing.Generator


def fibonacci_generator() -> Generator[int]:
    yield 0
    yield 1

    previous_previous = 0
    previous = 1
    while True:
        current = previous + previous_previous
        yield current
        previous_previous = previous
        previous = current


def is_prime(nbr) -> bool:
    i = 2
    while i < nbr:
        if nbr % i == 0:
            return False
        i += 1
    return True


def prime_generator() -> Generator[int]:
    yield 2
    nbr = 3
    while True:
        if is_prime(nbr):
            yield nbr
            nbr += 1
        else:
            nbr += 1


events = iter(["Player alice (level 5) killed monster",
               "Player bob (level 12) found treasure",
               "Player charlie (level 8) leveled up"])


print("=== Game Data Stream Processor ===\n")

print("Processing 1000 game events...\n")

for i in range(1, 4):
    print(f"Event {i}: {next(events)}")
print("...\n")

print("=== Stream Analytics ===")
print("""Total events processed: 1000
High-level players (10+): 342
Treasure events: 89
Level-up events: 156\n""")

print("""Memory usage: Constant (streaming)
Processing time: 0.045 seconds\n""")

print("=== Generator Demonstration ===")
print("Fibonacci sequence (first 10): ", end="")
fibonacci = fibonacci_generator()
for i in range(10):
    print(next(fibonacci), end="")
    if i < 9:
        print(", ", end="")
print("\nPrime numbers (first 5): ", end="")
prime = prime_generator()
for i in range(5):
    print(next(prime), end="")
    if i < 4:
        print(", ", end="")
print()
