fileNotFoundMessage = """RESPONSE: Archive not found in storage matrix
STATUS: Crisis handled, system stable"""
permissionErrorMessage = """RESPONSE: Security protocols deny access
STATUS: Crisis handled, security maintained"""
message = ""
successMessage = f"""SUCCESS: Archive recovered - ``{message}''
STATUS: Normal operations resumed"""

lost_archive = "lost_archive.txt"
classified_vault = "classified_vault.txt"
standard_archive = "standard_archive.txt"

print("=== CYBER ARCHIVES - CRISIS RESPONSE SYSTEM ===")

print(f"\nCRISIS ALERT: Attempting access to '{lost_archive}'...")
try:
    with open(lost_archive, "r") as file:
        message = file.read()
except FileNotFoundError:
    print(fileNotFoundMessage)
except Exception as err:
    print(f"[ERROR]: {err}")

print(f"\nCRISIS ALERT: Attempting access to '{classified_vault}'...")
try:
    with open(classified_vault, "r") as file:
        message = file.read()
except PermissionError:
    print(permissionErrorMessage)
except Exception as err:
    print(f"[ERROR]: {err}")

print(f"\nCRISIS ALERT: Attempting access to '{standard_archive}'...")
try:
    with open(standard_archive, "r") as file:
        message = file.read()
except Exception as err:
    print(f"[ERROR]: {err}")
else:
    successMessage = f"""SUCCESS: Archive recovered - ``{message}''
STATUS: Normal operations resumed"""
    print(successMessage)

print("\nAll crisis scenarios handled successfully. Archives secure.")
