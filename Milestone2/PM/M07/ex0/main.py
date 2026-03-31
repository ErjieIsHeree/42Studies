from ex0.CreatureCard import CreatureCard

fire_dragon = CreatureCard("Fire Dragon", 5, "Legendary", 7, 5)
goblin_warrior = CreatureCard("Goblin Warrior", 2, "Common", 2, 1)

print(f"""=== DataDeck Card Foundation ===

Testing Abstract Base Class Design:

CreatureCard Info:
{'name': 'Fire Dragon', 'cost': 5, 'rarity': 'Legendary',
'type': 'Creature', 'attack': 7, 'health': 5}

Playing Fire Dragon with 6 mana available:
Playable: {fire_dragon.is_playable(6)}
Play result: {fire_dragon.play({})}

Fire Dragon attacks Goblin Warrior:
Attack result: {fire_dragon.attack_target(goblin_warrior)}

Testing insufficient mana (3 available):
Playable: {fire_dragon.is_playable(3)}

Abstract pattern successfully demonstrated!""")
