from ex0.Card import Card


class SpellCard(Card):
    def __init__(self, name: str, cost: int, rarity: str, effect_type: str):
        super().__init__(name, cost, rarity)
        self.effect_type = effect_type
        pass

    def play(self, game_state: dict) -> dict:
        effect: str = "Unknown effect"
        if self.effect_type == "damage":
            effect = "Deal 3 damage to target"
        elif self.effect_type == "heal":
            effect = "Heal 3 hp to target"
        elif self.effect_type == "buff":
            effect = "Buff 1 shield to target"
        return {
            "card_played": self.name,
            "mana_used": self.cost,
            "effect": {effect}
        }

    def resolve_effect(self, targets: list) -> dict:
        effect: int = 0
        if self.effect_type == "damage":
            effect = -3
        elif self.effect_type == "heal":
            effect = 3
        elif self.effect_type == "buff":
            effect = 1
        for target in targets:
            if (target.health + effect) <= 0:
                target.health = 0
            else:
                target.health += effect
        return {}
    pass
