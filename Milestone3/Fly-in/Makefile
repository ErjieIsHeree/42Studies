install:
	python3 -m pip install -r requirements.txt

run: $(SRC)
	python3 $(SRC)

debug: $(SRC)
	python3 -m pdb $(SRC)

clean:
	find . -name __pycache__ -exec rm -rf {} +
	rm -rf .mypy_cache

lint:
	python3 -m flake8
	python3 -m mypy . --warn-return-any --warn-unused-ignores --ignore-missing-imports --disallow-untyped-defs --check-untyped-defs

lint-strict:
	python3 -m flake8
	python3 -m mypy . --strict
