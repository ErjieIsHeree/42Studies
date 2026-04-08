print("""=== Kaboom 0 ===
Access to alchemy/grimoire/dark_spellbook.py directly
Test import now - THIS WILL RAISE AN UNCAUGHT EXCEPTION""")
try:
    from alchemy.grimoire.dark_spellbook import dark_spell_record
    dark_spell_record("wow", "magic")
except ValueError:
    pass
