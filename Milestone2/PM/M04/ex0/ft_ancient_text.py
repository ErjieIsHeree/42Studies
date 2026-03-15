print("=== CYBER ARCHIVES - DATA RECOVERY SYSTEM ===")

print("\nAccessing Storage Vault: ancient_fragment.txt")
try:
    file = open("ancient_fragment.txt", "r")
    print("Connection established...")

    print("\nRECOVERED DATA:")
    print(file.read())

    file.close()
    print("\nData recovery complete. Storage unit disconnected.")
except Exception as err:
    print(f"[ERROR]: {err}")
