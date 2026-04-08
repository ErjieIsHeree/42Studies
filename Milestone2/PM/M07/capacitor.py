from ex1 import HealingCreatureFactory, TransformCreatureFactory


healing_creature_factory: HealingCreatureFactory = HealingCreatureFactory()
base_healing_creature = healing_creature_factory.create_base()
evolved_healing_creature = healing_creature_factory.create_evolved()

shapeshifter_creature_factory: TransformCreatureFactory = (
    TransformCreatureFactory()
)
base_shapeshifter_creature = shapeshifter_creature_factory.create_base()
evolved_shapeshifter_creature = shapeshifter_creature_factory.create_evolved()

print(f"""Testing Creature with healing capability
 base:
{base_healing_creature.describe()}
{base_healing_creature.attack()}
{base_healing_creature.heal()}
 evolved:
{evolved_healing_creature.describe()}
{evolved_healing_creature.attack()}
{evolved_healing_creature.heal()}

Testing Creature with transform capability
 base:
{base_shapeshifter_creature.describe()}
{base_shapeshifter_creature.attack()}
{base_shapeshifter_creature.transform()}
{base_shapeshifter_creature.attack()}
{base_shapeshifter_creature.revert()}
 evolved:
{evolved_shapeshifter_creature.describe()}
{evolved_shapeshifter_creature.attack()}
{evolved_shapeshifter_creature.transform()}
{evolved_shapeshifter_creature.attack()}
{evolved_shapeshifter_creature.revert()}""")
