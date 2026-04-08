from ex0 import FlameFactory, AquaFactory
from ex0.abs_creature import Creature
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex2 import (BattleStrategy, NormalStrategy, AggressiveStrategy,
                 DefensiveStrategy)


f_factory = FlameFactory()
a_factoty = AquaFactory()
h_factory = HealingCreatureFactory()
t_factory = TransformCreatureFactory()

normal_strat = NormalStrategy()
aggresive_strat = AggressiveStrategy()
defensive_strat = DefensiveStrategy()


def battle(opponents: list[tuple[Creature, BattleStrategy]]) -> None:
    idx: int = 1
    for opponent in opponents:
        for adversary in opponents[idx:]:
            print("\n* Battle *")
            print(opponent[0].describe())
            print("vs.")
            print(adversary[0].describe())
            print("now fight!")
            try:
                opponent[1].act(opponent[0])
                adversary[1].act(adversary[0])
            except Exception as err:
                print(f"Battle error, aborting tournament: {err}")
            pass
        idx += 1
    return


print("""Tournament 0 (basic)
[ (Flameling+Normal), (Healing+Defensive) ]
*** Tournament ***
2 opponents involved""")
battle([
    (f_factory.create_base(), normal_strat),
    (h_factory.create_base(), defensive_strat)
])

print("""\nTournament 1 (error)
[ (Flameling+Aggressive), (Healing+Defensive) ]
*** Tournament ***
2 opponents involved""")
battle([
    (f_factory.create_base(), aggresive_strat),
    (h_factory.create_base(), defensive_strat)
])

print("""\nTournament 2 (multiple)
[ (Aquabub+Normal), (Healing+Defensive), (Transform+Aggressive) ]
*** Tournament ***
3 opponents involved""")
battle([
    (a_factoty.create_base(), normal_strat),
    (h_factory.create_base(), defensive_strat),
    (t_factory.create_base(), aggresive_strat)
])
