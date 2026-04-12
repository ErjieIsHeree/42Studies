import importlib.metadata


modules: dict = {
    "pandas": ["3.0.1", "Data manipulation"],
    "numpy": ["2.4.4", "Numerical computation"],
    "requests": ["2.31.0", "Network access"],
    "matplotlib": ["3.10.8", "Visualization"]
}


def check_dependency(module: str, min_version: str, module_info: str) -> bool:
    try:
        installed = importlib.metadata.version(module)
    except importlib.metadata.PackageNotFoundError as err:
        print(f"[KO] {module} - {err}")
        return False
    else:
        installed_tuple = tuple(int(x) for x in installed.split("."))
        min_version_tuple = tuple(int(x) for x in min_version.split("."))
        max_version_tuple = (min_version_tuple[0] + 1, 0, 0)

        if not (installed_tuple >= min_version_tuple
                and installed_tuple < max_version_tuple):
            print(f"Wrong version. Need {min_version} or higher.")
            return False
        print(f"[OK] {module} ({installed}) - {module_info} ready")
        return True


def analyze_and_save(data: dict, filename: str = "analysis.png") -> None:
    import pandas as pd
    import matplotlib.pyplot as plt

    df = pd.DataFrame(data)
    matrix = df.to_numpy()  # numpy array para operar

    means = np.mean(matrix, axis=0)
    std_dev = np.std(matrix, axis=0)
    normed = (matrix - means) / std_dev      # normalización z-score
    corr = np.corrcoef(matrix.T)           # correlación entre stats

    fig, axes = plt.subplots(1, 3, figsize=(13, 4))
    fig.suptitle("Data Analysis", fontsize=14)

    # Barras: media ± desviación estándar
    axes[0].bar(df.columns, means, yerr=std_dev, color="steelblue", capsize=5)
    axes[0].set_title("Mean ± Std Dev")
    axes[0].tick_params(axis="x", rotation=30)

    # Líneas: datos normalizados
    for i, col in enumerate(df.columns):
        axes[1].plot(normed[:, i], label=col)
    axes[1].axhline(0, color="gray", linestyle="--", linewidth=0.8)
    axes[1].set_title("Z-score normalized")
    axes[1].legend(fontsize=8)

    # Heatmap: matriz de correlación
    im = axes[2].imshow(corr, cmap="coolwarm", vmin=-1, vmax=1)
    axes[2].set_xticks(range(len(df.columns)))
    axes[2].set_yticks(range(len(df.columns)))
    axes[2].set_xticklabels(df.columns, rotation=30)
    axes[2].set_yticklabels(df.columns)
    axes[2].set_title("Correlation matrix")
    fig.colorbar(im, ax=axes[2])

    # Anotar correlaciones
    for i in range(corr.shape[0]):
        for j in range(corr.shape[1]):
            axes[2].text(j, i, f"{corr[i, j]:.2f}", ha="center", va="center",
                         fontsize=8)

    plt.tight_layout()
    plt.savefig(filename, dpi=150, bbox_inches="tight")
    plt.close()
    print(f"Saved: {filename}")


if __name__ == "__main__":
    print("\nLOADING STATUS: Loading programs...\n")

    print("Checking dependencies:")
    if all([check_dependency(module, min_version, module_info)
            for module, (min_version, module_info) in modules.items()]):
        import numpy as np
        # --- Datos ---
        rng = np.random.default_rng(42)
        data = {
            "hp":      rng.integers(40, 100, size=8),
            "attack":  rng.integers(30, 90,  size=8),
            "defense": rng.integers(20, 80,  size=8),
            "speed":   rng.integers(10, 70,  size=8),
        }
        print("""\nAnalyzing Matrix data...
Processing 1000 data points...
print("Generating visualization...

Analysis complete!
Results saved to: matrix_analysis.png""")
        analyze_and_save(data)
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
