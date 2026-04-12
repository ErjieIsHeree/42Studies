from collections.abc import Callable


test_values = [18, 17, 8]
test_targets = ['Dragon', 'Goblin', 'Wizard', 'Knight']


def heal(target: str, power: int) -> str:
    return f"Heal restores {target} for {power} HP"


def fireball(target: str, power: int) -> str:
    return f"Fireball damages {target} for {power} HP"


def spell_combiner(
    spell1: Callable[[str, int], str],
    spell2: Callable[[str, int], str]
) -> Callable[[str, int], str]:
    def attack(target: str, power: int) -> str:
        return (f"{spell1(target, power)}, {spell2(target, power)}")
    return attack


def power_amplifier(
    base_spell: Callable[[str, int], str],
    multiplier: int
) -> Callable[[str, int], str]:
    def amplify(target: str, power: int) -> str:
        return (base_spell(target, power * multiplier))
    return amplify


def conditional_caster(
    condition: Callable[[str, int], bool],
    spell: Callable[[str, int], str]
) -> Callable[[str, int], str]:
    def attack(target: str, power: int) -> str:
        if condition(target, power):
            return spell(target, power)
        return "Spell fizzled"
    return attack


def spell_sequence(
    spells: list[Callable[[str, int], str]]
) -> Callable[[str, int], list[str]]:
    def attacks(target: str, power: int) -> list[str]:
        return [spell(target, power) for spell in spells]
    return attacks


print("Testing spell combiner...")
print(spell_combiner(heal, fireball)("Dragon", 40))

print("\nTesting power amplifier...")
print(power_amplifier(fireball, 4)("Dragon", 20))

print("\nTesting conditional caster...")
print(conditional_caster(lambda t, dmg: dmg > 10, heal)("Dragon", 30))

print("\nTesting spell squence...")
print(spell_sequence([heal, fireball])("Dragon", 20))
