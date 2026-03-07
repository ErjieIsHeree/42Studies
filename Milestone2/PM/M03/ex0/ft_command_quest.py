
import sys

argv: list[str] = sys.argv
argc: int = len(argv)

print("=== Command Quest ===")

if argc == 1:
    print("No arguments provided!")

print(f"Program name: {argv[0]}")

if argc != 1:
    print(f"Arguments received: {argc - 1}")

i = 1
while i < argc:
    print(f"Argument {i}: {argv[i]}")
    i += 1

print(f"Total arguments: {argc}")
