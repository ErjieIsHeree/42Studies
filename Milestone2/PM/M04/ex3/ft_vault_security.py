print("=== CYBER ARCHIVES - VAULT SECURITY SYSTEM ===\n")

print("Initiating secure vault access...")
try:
    with open("classified_data.txt", "r") as file:
        print("Vault connection established with failsafe protocols\n")

        print("SECURE EXTRACTION:")
        print(file.read())
except Exception as err:
    print(f"[ERROR]: {err}")

try:
    with open("security_protocols.txt", "w") as file:
        print("\nSECURE PRESERVATION:")
        print("[CLASSIFIED] New security protocols archived")
        file.write("[CLASSIFIED] New security protocols archived")
    print("Vault automatically sealed upon completion\n")
except Exception as err:
    print(f"[ERROR]: {err}")

print("All vault operations completed with maximum security.")
