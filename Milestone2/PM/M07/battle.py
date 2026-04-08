from ex0 import FlameFactory, AquaFactory

flame_factory: FlameFactory = FlameFactory()
flameling = flame_factory.create_base()
pyrodon = flame_factory.create_evolved()

aqua_factory: AquaFactory = AquaFactory()
aquabub = aqua_factory.create_base()
torragon = aqua_factory.create_evolved()

print(f"""Testing factory
{flameling.describe()}
{flameling.attack()}
{pyrodon.describe()}
{pyrodon.attack()}

Testing factory
{aquabub.describe()}
{aquabub.attack()}
{torragon.describe()}
{torragon.attack()}

Testing battle
{flameling.describe()}
vs.
{aquabub.describe()}
fight!
{flameling.attack()}
{aquabub.attack()}""")
