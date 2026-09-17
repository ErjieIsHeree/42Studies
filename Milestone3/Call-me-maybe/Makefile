
SRC:=src.call_me_maybe
FUNC_DEF:=data/input/functions_definition.json
INPUT_F:=data/input/function_calling_tests.json
OUTPUT_F:=data/output/function_calls.json
EXTRA_DATA:=--functions_definition $(FUNC_DEF) --input $(INPUT_F)  --output $(OUTPUT_F)

install:
	python3 -m pip -r requirements.txt

# Remember to run 'export HF_HOME=/sgoinfre/students/exia/.hf-cache' before starting"
run:
	export UV_CACHE_DIR=/sgoinfre/students/exia/.uv-cache
	uv run python3 -m $(SRC) $(EXTRA_DATA)

debug:
	python3 -m pdb $(SRC)

clean:
	find . -name __pycache__ -exec rm -rf {} +
	rm -rf .mypy_cache

lint:
	python3 -m flake8 .
	python3 -m mypy . --warn-return-any --warn-unused-ignores --ignore-missing-imports --disallow-untyped-defs --check-untyped-defs

lint-strict:
	python3 -m flake8 .
	python3 -m mypy . --strict