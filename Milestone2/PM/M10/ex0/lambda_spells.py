
def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    return sorted(artifacts, key=lambda artifact: artifact["power"])


def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    return list(filter(lambda mage: mage["power"] > min_power, mages))


def spell_transformer(spells: list[str]) -> list[str]:
    return list(map(lambda spell: f"* {spell} *", spells))


def mage_stats(mages: list[dict]) -> dict:
    strongest = max(mages, key=lambda mage: mage["power"])
    weakest = min(mages, key=lambda mage: mage["power"])
    average = round((sum([mage["power"] for mage in mages]) / len(mages)), 2)
    return {"max_power": strongest, "min_power": weakest, "avg_power": average}


artifacts = [
    {'name': 'Earth Shield', 'power': 85, 'type': 'focus'},
    {'name': 'Earth Shield', 'power': 87, 'type': 'focus'},
    {'name': 'Wind Cloak', 'power': 69, 'type': 'relic'},
    {'name': 'Water Chalice', 'power': 70, 'type': 'relic'}
]
mages = [
    {'name': 'Jordan', 'power': 91, 'element': 'lightning'},
    {'name': 'Casey', 'power': 71, 'element': 'earth'},
    {'name': 'Ember', 'power': 91, 'element': 'lightning'},
    {'name': 'Riley', 'power': 98, 'element': 'fire'},
    {'name': 'Casey', 'power': 63, 'element': 'water'}
]
spells = ['tsunami', 'fireball', 'freeze', 'blizzard']


print("Testing artifact sorter...")
for i, artifact in enumerate(artifact_sorter(artifacts), start=1):
    print(f"{artifact['name']} ({artifact['power']} power)", end="")
    if i < len(artifacts):
        print(" comes before ", end="")


print("\n\nTesting power filter...")
for mage in power_filter(mages, 90):
    print(f"The mage {mage['name']} of power {mage['power']}")


print("\n\nTesting spell transformer...")
for spell in spell_transformer(spells):
    print(f"{spell} ", end="")


print("\n\nTesting mage stats...")
stats = mage_stats(mages)
print(f"""Max power: {stats['max_power']}, min power: {stats['min_power']},""",
      end="")
print(f" average power: {stats['avg_power']}")
