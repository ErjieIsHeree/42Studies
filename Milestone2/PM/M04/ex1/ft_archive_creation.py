print("=== CYBER ARCHIVES - DATA RECOVERY SYSTEM ===")

print("\nInitializing new storage unit: new_discovery.txt")
try:
    with open("new_discovery.txt", "w") as file:
        print("Storage unit created successfully...")

        print("\nInscribing preservation data...")
        print("""[ENTRY 001] New quantum algorithm discovered
[ENTRY 002] Efficiency increased by 347%
[ENTRY 003] Archived by Data Archivist trainee""")
        file.write("""[ENTRY 001] New quantum algorithm discovered
[ENTRY 002] Efficiency increased by 347%
[ENTRY 003] Archived by Data Archivist trainee""")

        print("\nData inscription complete. Storage unit sealed.")
        print("Archive 'new_discovery.txt' ready for long-term preservation.")
except Exception as err:
    print(f"[ERROR]: {err}")
