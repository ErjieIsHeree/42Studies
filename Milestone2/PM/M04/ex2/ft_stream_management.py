
import sys

print("=== CYBER ARCHIVES - COMMUNICATION SYSTEM ===")

act_id: str = input("Input Stream active. Enter archivist ID: ")
status_rep: str = input("Input Stream active. Enter status report: ")
print()

print(f"[STANDARD] Archive status from {act_id}: {status_rep}",
      file=sys.stdout)
print("[ALERT] System diagnostic: Communication channels verified",
      file=sys.stderr)
print("[STANDARD] Data transmission complete", file=sys.stdout)

print("\nThree-channel communication test successful.")
