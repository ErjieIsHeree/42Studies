
alice_achievements: set = {'first_kill', 'level_10', 'treasure_hunter',
                           'speed_demon'}
bob_achievements: set = {'first_kill', 'level_10', 'boss_slayer', 'collector'}
charlie_achievements: set = {'level_10', 'treasure_hunter', 'boss_slayer',
                             'speed_demon', 'perfectionist'}

print("=== Achievement Tracker System ===\n")

print(f"Player alice achievements: {alice_achievements}")
print(f"Player bob achievements: {bob_achievements}")
print(f"Player charlie achievements: {charlie_achievements}\n")

print("=== Achievement Analytics ===")
print(f"All unique achievements: {alice_achievements.union(bob_achievements,
      charlie_achievements)}")
print(f"Total unique achievements: {len(alice_achievements.union(
    bob_achievements, charlie_achievements))}\n")

print(f"Common to all players: {alice_achievements.intersection(
    bob_achievements, charlie_achievements)}")
print(f"Rare achievements (1 player): {alice_achievements
      .difference(bob_achievements, charlie_achievements)
      .union(
          bob_achievements
          .difference(alice_achievements, charlie_achievements),
          charlie_achievements
          .difference(alice_achievements, bob_achievements))}\n")

print(f"Alice vs Bob common: {alice_achievements
      .intersection(bob_achievements)}")
print(f"Alice unique: {alice_achievements.difference(bob_achievements)}")
print(f"Bob unique: {bob_achievements.difference(alice_achievements)}")
