from typing import Callable, Any
import functools
import operator


def spell_reducer(spells: list[int], operation: str) -> int:
    if operation.lower() == "add":
        return functools.reduce(lambda acc, x: operator.add(acc, x), spells)
    elif operation.lower() == "multiply":
        return functools.reduce(lambda acc, x: operator.mul(acc, x), spells)
    elif operation.lower() == "max":
        return functools.reduce(lambda acc, x: acc if operator.gt(acc, x)
                                else x, spells)
    elif operation.lower() == "min":
        return functools.reduce(lambda acc, x: acc if operator.lt(acc, x)
                                else x, spells)
    return 0


def base_enchantment(power: int, element: str, target: str) -> str:
    return f"{element} attack deals {target} {power} damage points"


def partial_enchanter(base_enchantment: Callable) -> dict[str, Callable]:
    return {
        "Air": functools.partial(base_enchantment, 50, "Air"),
        "Fire": functools.partial(base_enchantment, 50, "Fire"),
        "Water": functools.partial(base_enchantment, 50, "Water"),
        "Earth": functools.partial(base_enchantment, 50, "Earth"),
        "Plant": functools.partial(base_enchantment, 50, "Plant")
    }


@functools.lru_cache()
def memoized_fibonacci(n: int) -> int:
    if n <= 1:
        return n
    return memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2)


def spell_dispatcher() -> Callable[[Any], str]:
    @functools.singledispatch
    def spell(spell: Any) -> str:
        return "Unknown spell type"

    @spell.register
    def _(spell: int) -> str:
        return f"{spell} damage"

    @spell.register
    def _(spell: str) -> str:
        return f"{spell}"

    @spell.register
    def _(spell: list) -> str:
        return f"{len(spell)} spells"

    return spell


if __name__ == "__main__":
    spell_powers = [15, 35, 42, 47, 33, 39]
    operations = ['add', 'multiply', 'max', 'min']
    fibonacci_tests = [14, 9, 9]

    spell = spell_dispatcher()

    print(f"""Testing spell reducer...
Sum: {spell_reducer([50, 50], operations[0])}
Product: {spell_reducer([120000, 2], operations[1])}
Max: {spell_reducer([40, 1, 2, 3], operations[2])}

Testing memoized fibonacci...
Fib(0): {memoized_fibonacci(0)}
Fib(1): {memoized_fibonacci(1)}
Fib(10): {memoized_fibonacci(10)}
Fib(15): {memoized_fibonacci(15)}

Testing spell dispatcher...
Damage spell: {spell(42)}
Enchantment: {spell("fireball")}
Multi-cast: {spell([1, 2, 3])}
{spell(1.1)}""")
