import os
import site
import sys

current_python = sys.executable

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
