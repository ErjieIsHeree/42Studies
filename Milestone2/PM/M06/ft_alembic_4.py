import alchemy

print(f"""=== Alembic 4 ===
Accessing the alchemy module using 'import alchemy'
Testing create_air: {alchemy.create_air()}
Now show that not all functions can be reached
This will raise an exception!""")
alchemy.create_earth()
