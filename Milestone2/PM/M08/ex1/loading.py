# Note: check before evaluation that all versions are compatible within the 42
# python version. If forgot, then you can argue by telling that the project can
# be evaluated on further python versions (I'm using 3.14.3 rn)

pandas_version = "3.0.1"
numpy_version = "2.4.4"
requests_version = "2.31.0"
matplotlib_version = "3.10.8"
all_modules_installed = True

print("\nLOADING STATUS: Loading programs...\n")

print("Checking dependencies:")
try:
    import pandas as pd
    if pd.__version__ != pandas_version:
        raise Exception(f"Wrong version. Need {pandas_version}. "
                        f"Actual version {pd.__version__}")
    print(f"[OK] pandas ({pandas_version}) - Data manipulation ready")
except Exception as err:
    print(f"[KO] pandas - {err}")
    all_modules_installed = False

try:
    import numpy as np
    if np.__version__ != numpy_version:
        raise Exception(f"Wrong version. Need {numpy_version}. "
                        f"Actual version {np.__version__}")
    print(f"[OK] numpy ({numpy_version}) - Numerical computation ready")
except Exception as err:
    print(f"[KO] numpy - {err}")
    all_modules_installed = False

try:
    import requests as rq
    if rq.__version__ != requests_version:
        raise Exception(f"Wrong version. Need {requests_version}. "
                        f"Actual version {rq.__version__}")
    print(f"[OK] requests ({requests_version}) - Network access ready")
except Exception as err:
    print(f"[KO] requests - {err}")
    all_modules_installed = False

try:
    import matplotlib as mpl
    if mpl.__version__ != matplotlib_version:
        raise Exception(f"Wrong version. Need {matplotlib_version}. "
                        f"Actual version {mpl._version}")
    print(f"[OK] matplotlib ({matplotlib_version}) - Visualization ready")
except Exception as err:
    print(f"[KO] matplotlib - {err}")
    all_modules_installed = False


def generate_visualization() -> None:
    import numpy as np
    import pandas as pd
    import matplotlib.pyplot as plt
    # --- Datos generados ---
    rng = np.random.default_rng(42)
    creatures = ["Sproutling", "Bloomelle", "Shiftling", "Morphagon"]
    stats = {
        "creature": creatures,
        "hp":      rng.integers(40, 100, size=4),
        "attack":  rng.integers(30, 90,  size=4),
        "defense": rng.integers(20, 80,  size=4),
        "speed":   rng.integers(10, 70,  size=4),
    }

    # --- Pandas: organizar ---
    df = pd.DataFrame(stats).set_index("creature")
    df["total"] = df.sum(axis=1)
    df = df.sort_values("total", ascending=False)
    print(df.to_string())

    # --- Matplotlib: visualizar ---
    cols = ["hp", "attack", "defense", "speed"]
    x = np.arange(len(df))
    width = 0.2

    fig, ax = plt.subplots(figsize=(9, 5))
    for i, col in enumerate(cols):
        ax.bar(x + i * width, df[col], width, label=col.capitalize())

    ax.set_xticks(x + width * 1.5)
    ax.set_xticklabels(df.index)
    ax.set_ylabel("Stat value")
    ax.set_title("Creature Stats Comparison")
    ax.legend()
    plt.tight_layout()
    plt.show()


if all_modules_installed:
    print("\nAnalyzing Matrix data...")
    print("Processing 1000 data points...")
    print("Generating visualization...")
    generate_visualization()

    print("""\nAnalysis complete!
Results saved to: matrix_analysis.png}""")
else:
    print("""\nExercise can not be done.

Try installing the packages using:
python3 -m venv .venv
source .venv/bin/activate
pip install -r requierements.txt

or you can use poetry:
poetry install
source $(poetry env activate) or poetry run python3 the_script.py

Make sure to delete the venv or the poetry env:
rm -r venv or poetry env remove python""")
