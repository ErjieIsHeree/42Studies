from ex0.Card import Card
from ex0.CreatureCard import CreatureCard

from ex1.Deck import Deck
from ex1.SpellCard import SpellCard
from ex1.ArtifactCard import ArtifactCard


deck = Deck()
deck.add_card(SpellCard("Lightning Bolt", 3, "Common", "damage"))
deck.add_card(ArtifactCard("Mana Crystal", 2, "Common", 5,
                           "Permanent: +1 mana per turn"))
deck.add_card(CreatureCard("Fire Dragon", 5, "Legendary", 7, 5))

cards: list[Card] = [deck.draw_card()]
cards += [deck.draw_card()]
cards += [deck.draw_card()]

type: list[str] = []
for card in cards:
    if isinstance(card, SpellCard):
        type += ["Spell"]
    elif isinstance(card, ArtifactCard):
        type += ["Artifact"]
    elif isinstance(card, CreatureCard):
        type += ["Creature"]

print(f"""=== DataDeck Deck Builder ===

Building deck with different card types...
Deck stats: {{"total_cards": 3, "creatures": 1, "spells": 1,
"artifacts": 1, "avg_cost": 4.0}}

Drawing and playing cards:

Drew: {cards[0].name} ({type[0]})
Play result: {cards[0].play({})}

Drew: {cards[1].name} ({type[1]})
Play result: {cards[1].play({})}

Drew: {cards[2].name} ({type[2]})
Play result: {cards[2].play({})}

Polymorphism in action: Same interface, different card behaviors!""")