from ex0.Card import Card
from ex0.CreatureCard import CreatureCard

from ex1.SpellCard import SpellCard
from ex1.ArtifactCard import ArtifactCard

import random


class Deck():
    cards: list[Card] = []

    def add_card(self, card: Card) -> None:
        self.cards.append(card)
        pass

    def remove_card(self, card_name: str) -> bool:
        original_length = len(self.cards)
        self.cards = [card for card in self.cards if card.name != card_name]
        return original_length > len(self.cards)

    def shuffle(self) -> None:
        random.shuffle(self.cards)
        pass

    def draw_card(self) -> Card:
        return random.choice(self.cards)

    def get_deck_stats(self) -> dict:
        return {
            "total_cards": len(self.cards),
            "creatures": len(
                [card for card in self.cards if isinstance(card, CreatureCard)]
            ),
            "spells": len(
                [card for card in self.cards if isinstance(card, SpellCard)]
            ),
            "artifacts": len(
                [card for card in self.cards if isinstance(card, ArtifactCard)]
            ),
            "avg_cost": round((sum([card.cost for card in self.cards]) / 
                               len(self.cards)), 1)
        }

    pass
