import sys

print("=== CYBER ARCHIVES - COMMUNICATION SYSTEM ===\n")

act_id: str = input("Input Stream active. Enter archivist ID: ")
status_rep: str = input("Input Stream active. Enter status report: ")

print(f"\n[STANDARD] Archive status from {act_id}: {status_rep}")
print("[ALERT] System diagnostic: Communication channels verified",
      file=sys.stderr)
print("[STANDARD] Data transmission complete")

print("\nThree-channel communication test successful.")
