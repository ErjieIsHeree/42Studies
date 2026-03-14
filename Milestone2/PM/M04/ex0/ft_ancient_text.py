print("=== CYBER ARCHIVES - DATA RECOVERY SYSTEM ===")

print("Accessing Storage Vault: ancient_fragment.txt")
try:
    file = open("ancient_fragment.txt", "r")
    print("Connection established...")

    print("\nRECOVERED DATA:")
    print(file.read())

    file.close()
    print("Data recovery complete. Storage unit disconnected.")
except FileNotFoundError:
    print("ERROR: Storage vault not found.")
