import os
import site
import sys

# Before starting, you will hear the name "venv" a along the comments. So a
# quick introduction to them here. A venv (virtual enviroment) is a reserved
# space that a program/module/app/... use for it's execution, it contains
# imported modules and idk what else (but in resume, needs of the program form
# that are unaffiliated to this). It makes lot of things easier, but I won't
# tell you, you will see it if you are starting at python. Not from me, im lazy
# rn.

# ATTENTION: I just noticed I mentioned root all along the exercise. Welp,
# all of them are refering to absolute roots from home/. OK?

# executable atributte from sys module contain the root to the python
# executable being used right now (so if we are using a venv, it will return
# the root to the python executable contained in the venv)
current_python = sys.executable

# prefix and base_prefix both contain the root to a venv of python. The only
# difference is that base_prefix will always return the global venv and prefix
# always return the venv that is being used to execute the file

if sys.base_prefix == sys.prefix:
    print(f"""MATRIX STATUS: You're still plugged in

Current Python: {current_python}
Virtual Environment: None detected

WARNING: You're in the global environment!
The machines can see everything you install.

To enter the construct, run:
python -m venv matrix_env
source matrix_env/bin/activate # On Unix
matrix_env
Scripts
activate    # On Windows

Then run this program again.""")
else:
    # Activating a venv entails the creation/modification of a enviroment
    # variable named "VIRTUAL_ENV", containing the root to the venv being used
    # rn.

    # And the function basename from the variable path of the module os just
    # take a string and get the string after the last "/" character.
    venv_path = os.environ.get("VIRTUAL_ENV", "")
    venv_name = os.path.basename(venv_path)
    print(f"""MATRIX STATUS: Welcome to the construct

Current Python: {current_python}
Virtual Environment: {venv_name}
Environment Path: {venv_path}

SUCCESS: You're in an isolated environment!
Safe to install packages without affecting
the global system.

Package installation path:
{site.getsitepackages()[1]}""")
