
SRC:=

install:
	python3 -m pip -r requirements.txt

run:
	python3 $(SRC)

debug:
	find . -name __pycache__ -exec rm -rf {} +
	rm -rf .mypy_cache

clean:
	rm -rf 

lint:
	python3 -m flake8 .
	python3 -m mypy . --warn-return-any --warn-unused-ignores --ignore-missing-imports --disallow-untyped-defs --check-untyped-defs

lint-strict:
	python3 -m flake8 .
	python3 -m mypy . --strict