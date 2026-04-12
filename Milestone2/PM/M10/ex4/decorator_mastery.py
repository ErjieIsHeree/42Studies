from functools import wraps
from collections.abc import Callable
from typing import Any
import time
import re


def spell_timer(func: Callable) -> Callable:
    @wraps(func)
    def wrapper(*args, **kwargs) -> Any:
        print(f"Casting {func.__name__}...")
        start = time.perf_counter()
        any: Any = func(*args, **kwargs)
        print(f"Spell completed in {(time.perf_counter() - start):.3f} second"
              "s")
        return any
    return wrapper


@spell_timer
def fireball() -> str:
    time.sleep(0.101)
    return "Fireball cast!"


def power_validator(min_power: int) -> Callable:
    def _(func: Callable) -> Callable:
        @wraps(func)
        def wrapper(*args, **kwargs) -> Any:
            if args[2] >= min_power:
                return func(*args, **kwargs)
            else:
                return "Insufficient power for this spell"
        return wrapper
    return _


def retry_spell(max_attempts: int) -> Callable:
    def _(func: Callable) -> Callable:
        @wraps(func)
        def wrapper() -> Any:
            for i, _ in enumerate(range(max_attempts), 1):
                try:
                    return func()
                except Exception:
                    print(f"Spell failed, retrying... {i}/{max_attempts}")
        return wrapper
    return _


@retry_spell(3)
def bad_spell() -> None:
    raise Exception()


@retry_spell(3)
def good_spell() -> str:
    return "Waaaaaaagh spelled !"


class MageGuild:
    @staticmethod
    def validate_mage_name(name: str) -> bool:
        if re.match(r"^[a-zA-Z ]{3,}$", name):
            return True
        return False

    @power_validator(10)
    def cast_spell(self, spell_name: str, power: int) -> str:
        return f"Successfully cast {spell_name} with {power} power"
    pass


if __name__ == "__main__":
    mage_guild: MageGuild = MageGuild()

    print("Testing spell timer...")
    result: str = fireball()
    print(f"""Result: {result}

Testing retrying spell...""")
    bad_spell()
    print(f"""Spell casting failed after 3 attempts
{good_spell()}

Testing MageGuild...
{MageGuild.validate_mage_name("Hell")}
{MageGuild.validate_mage_name("Na")}
{mage_guild.cast_spell("Lightning", 15)}
{mage_guild.cast_spell("Lightning", 9)}""")
