from collections.abc import Callable


def mage_counter() -> Callable:
    count: int = 0

    def counter() -> int:
        nonlocal count
        count += 1
        return count

    return counter


def spell_accumulator(initial_power: int) -> Callable:
    def accumulate(add: int) -> int:
        nonlocal initial_power
        initial_power += add
        return initial_power

    return accumulate


def enchantment_factory(enchantment_type: str) -> Callable:
    def enchant(item_name: str) -> str:
        return f"{enchantment_type.capitalize()} {item_name.capitalize()}"

    return enchant


def memory_vault() -> dict[str, Callable]:
    vault: dict[str, str] = {}

    def store(key: str, value: str) -> None:
        vault[key] = value
        return

    def recall(key: str) -> str:
        return vault.get(key, "Memory not found")

    return {"store": store, "recall": recall}


if __name__ == "__main__":
    initial_powers = [66, 37, 76]
    power_additions = [16, 6, 11, 18, 14]
    enchantment_types = ['Flaming', 'Flowing', 'Windy']
    items_to_enchant = ['Sword', 'Cloak', 'Wand', 'Staff']

    counter_a: Callable = mage_counter()
    counter_b: Callable = mage_counter()

    acumulated_spell: Callable = spell_accumulator(100)

    flaming_enchant_factory: Callable = enchantment_factory("flaming")
    frozen_enchant_factory: Callable = enchantment_factory("frozen")

    store, recall = memory_vault().values()
    store("secret", "42")

    print(f"""Testing mage counter...
counter_a call 1: {counter_a()}
counter_a call 2: {counter_a()}
counter_b call 1: {counter_b()}

Testing spell accumulator...
Base 100, add 20: {acumulated_spell(20)}
Base 100, add 30: {acumulated_spell(30)}

Testing enchantment factory...
{flaming_enchant_factory("sword")}
{frozen_enchant_factory("Shield")}

Testing memory vault...
Store 'secret' = 42
Recall 'secret': {recall("secret")}
Recall 'unknown': {recall("unknown")}""")
