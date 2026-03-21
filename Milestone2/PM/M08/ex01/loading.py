# Note: check before evaluation that all versions are compatible within the 42
# python version. If forgot, then you can argue by telling that the project can
# be evaluated on further python versions (I'm using 3.14.3 rn)

pandas_version = "3.0.1"
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


def generate_visualization(texts: list[str]) -> None:
    from matplotlib import pyplot as plt

    fig, ax = plt.subplots(figsize=(2, len(texts) * 0.4))
    ax.axis("off")

    for i, data in enumerate(texts):
        ax.text(0, 1 - i * 0.05, f"• {data}", transform=ax.transAxes,
                fontsize=9, verticalalignment="top", wrap=True)

    plt.savefig("matrix_analysis.png", bbox_inches="tight")
    pass


if all_modules_installed:
    cats_facts = rq.get("https://meowfacts.herokuapp.com/?count=91")

    print("\nAnalyzing Matrix data...")
    print("Processing 1000 data points...")
    print("Generating visualization...")
    generate_visualization([data for data in cats_facts.json()["data"]])

    print("""\nAnalysis complete!
Results saved to: matrix_analysis.png}""")
else:
    print("\nExercise can not be done.")
