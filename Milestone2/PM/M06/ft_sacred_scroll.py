import alchemy
from typing import Generator


def create_gen() -> Generator[str]:
    try:
        alchemy.create_earth()
    except Exception:
        yield "AttributeError - not exposed"
    try:
        alchemy.create_air()
    except Exception:
        yield "AttributeError - not exposed"


create = create_gen()

print("=== Sacred Scroll Mastery ===\n")

print(f"""Testing direct module access:
alchemy.elements.create_fire(): {alchemy.elements.create_fire()}
alchemy.elements.create_water(): {alchemy.elements.create_water()}
alchemy.elements.create_earth(): {alchemy.elements.create_earth()}
alchemy.elements.create_air(): {alchemy.elements.create_air()}

Testing package-level access (controlled by __init__.py):
alchemy.create_fire(): {alchemy.create_fire()}
alchemy.create_water(): {alchemy.create_water()}
alchemy.create_earth(): {next(create)}
alchemy.create_air(): {next(create)}

Package metadata:
Version: {alchemy.__version__}
Author: {alchemy.__author__}""")
