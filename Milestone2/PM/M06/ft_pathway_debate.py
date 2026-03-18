import alchemy.transmutation
from alchemy.transmutation import philosophers_stone, elixir_of_life
from alchemy.transmutation.basic import lead_to_gold, stone_to_gem

print(f"""=== Pathway Debate Mastery ===

Testing Absolute Imports (from basic.py):
lead_to_gold(): {lead_to_gold()}
stone_to_gem(): {stone_to_gem()}

Testing Relative Imports (from advanced.py):
philosophers_stone(): {philosophers_stone()}
elixir_of_life(): {elixir_of_life()}

Testing Package Access:
alchemy.transmutation.lead_to_gold(): {alchemy.transmutation.lead_to_gold()}
alchemy.transmutation.philosophers_stone(): """
      f"""{(alchemy.transmutation.philosophers_stone())}

Both pathways work! Absolute: clear, Relative: concise""")
