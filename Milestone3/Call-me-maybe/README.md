_This project has been created as part of the 42 curriculum by exia._

# Call Me Maybe — Introduction to Function Calling in LLMs

## Description

**Goal.** Turn natural-language requests into structured, machine-executable
function calls using a small LLM (`Qwen/Qwen3-0.6B`, 0.6B parameters) and
**constrained decoding**, so that the emitted JSON is valid and schema-compliant
_by construction_ rather than by luck.

A 0.6B model asked to "just print JSON" succeeds only a few times out of ten. This
project reaches 100% parseable, structurally-correct output on the provided test
set by never letting the model choose a token that would break the target
structure. See [Performance analysis](#performance-analysis) for the measured
numbers.

**What it does.** Given a list of prompts and a catalogue of function signatures,
the program emits, for every prompt, the name of the function to call and its typed
arguments:

```json
[
    {
        "prompt": "What is the sum of 2 and 3?",
        "name": "fn_add_numbers",
        "parameters": { "a": 2, "b": 3 }
    }
]
```

Note it does **not** answer the question (it does not return `5`). It returns the
_call_ that would answer it.

**Overview of the pipeline.**

1. Load and JSON-Schema-validate both input files.
2. Build a ChatML-style prompt containing the function catalogue in `<tools>`
   tags plus a one-shot example of the expected answer shape.
3. Generate the answer token by token, driving a finite-state machine whose
   states each carry a regex describing what the text must look like.
4. At every step, either inject the forced structural tokens or sample the model's
   most likely token, and advance only when the accumulated text matches the
   state's regex.
5. Ban every non-EOS token until EOS becomes the argmax, guaranteeing the object
   terminates.
6. Assemble the objects into a single JSON array and write it out.

## Instructions

Requirements: Python 3.10+, and [uv](https://docs.astral.sh/uv/).

```bash
# Install dependencies (creates .venv, uses the bundled llm_sdk workspace member)
uv sync

# Run with the default paths
uv run python -m src.call_me_maybe
```

The model is pulled from the Hugging Face Hub on first run (~1.2 GB). Set
`HF_HOME` beforehand if you want to control the cache location.

Inputs are read from `data/input/` and the result is written to
`data/output/function_calling_results.json` by default. All three paths are
overridable:

```bash
uv run python -m src.call_me_maybe \
    --functions_definition data/input/functions_definition.json \
    --input data/input/function_calling_tests.json \
    --output data/output/function_calling_results.json
```

The `Makefile` wraps the usual tasks: `make install`, `make run`, `make debug`
(launches under `pdb`), `make clean`, `make lint`, `make lint-strict`.

> Note: `make lint` currently runs `flake8 .` over the whole tree, which walks
> into `.venv` and blows up pyflakes' recursion limit. `uv run python -m flake8 src/`
> exits 0. `mypy` is not yet a declared dependency, so the `lint` targets cannot
> run as written — see [Known limitations](#known-limitations).

## Resources

**Topic references**

- Qwen3 model card — <https://huggingface.co/Qwen/Qwen3-0.6B>
- Qwen3 chat template (source of the `<|im_start|>` / `<|im_end|>` / `<think>`
  scaffolding used here) — <https://huggingface.co/Qwen/Qwen3-0.6B/blob/main/tokenizer_config.json>
- The Qwen2.5/Qwen3 technical report on reasoning-model formats — <https://arxiv.org/abs/2505.09388>
- Hugging Face, _Theoretical analysis of constrained decoding_ /
  `generate` guide on `prefix_allowed_tokens_fn` and logits processors —
  <https://huggingface.co/docs/transformers/main_classes/text_generation>
- Outlines, the library that generalises this pattern to arbitrary grammars and
  JSON schemas — <https://github.com/dottxt-ai/outlines>
- Grammar-constrained decoding, a good survey of the field —
  <https://arxiv.org/abs/2305.13634>

**How AI was used in this project**

- **Tooling and scaffolding.** `pyproject.toml`, the `Makefile`, the
  `argparse` CLI skeleton, and the `src/` → `domain/application/infrastructure`
  package layout were scaffolded with AI assistance and then rewritten by hand.
- **Exploration and diagnosis.** The state machine's six regexes, the
  `<tool_call>` / `<think>` prompt design, and the EOS-banning loop were
  arrived at by iterating with AI on failing generations — in particular,
  diagnosing a JSON syntax error that turned out to be a double-comma artifact
  from token injection in the parameters state.
- **Documentation.** Docstrings, commit messages, and this README were drafted
  with AI and reviewed line by line.

**What was _not_ delegated.** The constrained-decoding logic itself
(`domain/services.py`), the input validation schemas, and the use-case
orchestration were all written, debugged, and understood by hand — these are the
parts that get defended during peer review, and the subject explicitly forbids
relying on the model to produce correct JSON by prompting alone.

## Algorithm explanation

### 1. The prompt

`domain/constants.py` builds a ChatML-style prompt:

```
<|im_start|>system
# Tools

You may call one or more functions to assist with the user query.

You are provided with function signatures within <tools></tools> XML tags:
<tools>
{functions}
</tools>

For each function call, return a json object with prompt, function name and
arguments within <tool_call></tool_call> XML tags, like:
<tool_call>
{example}
</tool_call><|im_end|>
<|im_start|>user
```

The user prompt is appended, followed by `E_PROMPT`, which opens the assistant
turn, emits an _empty_ `<think>` block (Qwen3 is a hybrid reasoning model — an
explicit empty think block suppresses visible reasoning so the answer starts
immediately), opens `<tool_call>`, and forces the object to begin with
`{\n    "prompt": `.

Giving the model a concrete shape to continue, then constraining everything after
that opening prefix, is what makes the small model reliable.

### 2. The state machine

`domain/services.py::StateMachine` holds a list of six regexes, one per state.
State `i` may advance to `i + 1` only when the whole answer generated so far
matches `sequence[i]`.

| State | Regex                          | Role                                             | Who emits the tokens |
| ----- | ------------------------------ | ------------------------------------------------ | -------------------- |
| 0     | `{\n    "prompt":[^\n]*\n$`    | the prompt string, closing quote and newline     | **model** (argmax)   |
| 1     | `    "name":`                  | the `"name"` key                                 | **forced**           |
| 2     | `[^\n]*\n$`                    | the function name, closing quote, comma, newline | **model** (argmax)   |
| 3     | `    "parameters": {\n       ` | the `"parameters"` key and opening brace         | **forced**           |
| 4     | `[^\n]*[^,]\n$`                | the parameter entries                            | **model** (argmax)   |
| 5     | `    }\n}\n`                   | closing braces                                   | **forced**           |

Three details make this work:

- **Anchoring with `$`.** Every model-driven state ends with `\n$`, so the model
  cannot emit a newline mid-value. One value per state, one state per value.
- **The `[^,]` in state 4.** The last character before the newline must not be a
  comma. This is what prevents a trailing comma in the `"parameters"` object,
  which is the single most common way a 0.6B model emits invalid JSON here.
- **Forced states cost no forward pass.** `get_state_need` returns the tokens of
  the literal itself, and the whole literal is appended in one go. The model is
  only invoked for states 0, 2 and 4, so a complete answer needs roughly
  `len(prompt) + len(name) + len(parameters) + 1` model calls, not
  `len(answer)`.

### 3. Forced vs. sampled tokens

`get_state_need(state, tokenized_prompt)` is the single decision point:

```python
if state in (1, 3, 5):          # structural
    return self.llm.tokenize(self.sequence[state])
else:                            # semantic
    return [int(np.argmax(self.llm.generate_logits(tokenized_prompt)))]
```

### 4. Termination

The loop exits when the state reaches `end_state` (6). At that point the
`parameters` object is still open, so one final call to
`random_constrained_decode` guarantees a clean stop:

```python
tk_id = int(np.argmax(logits))
while tk_id != 151658:          # Qwen3 <|im_end|>
    logits[tk_id] = float("-inf")
    tk_id = int(np.argmax(logits))
```

Each round the current best token is banned by setting its logit to `-inf` and
the argmax is recomputed. The loop terminates as soon as EOS is the most likely
remaining token, so the model stops at the earliest point it considers the answer
finished — and never before, because banning cannot introduce a token, only
remove one. The EOS id is then discarded before decoding, so it never appears in
the output.

### 5. Assembly

`_generate_answer` concatenates each per-prompt answer with `,` separators and
wraps the result in `[` … `]`, guaranteeing a single well-formed array whose
elements each came from a machine that could only ever emit valid object syntax.

## Design decisions

**Clean architecture, three layers.** `domain/` holds interfaces, constants and
the decoding logic; `application/` holds the use case; `infrastructure/` holds
the concrete I/O and the `Small_LLM_Model` adapter. The dependency arrow points
inward only — `application` imports from `domain`, and `__main__` is the sole
composition root that knows about all three. This is what makes the LLM swappable.

**Pydantic everywhere, as the subject requires.** Not just for the data — for the
behaviour too. `StateMachine`, `ProcessFunctionCalling`, `JsonReader`,
`JsonWriter` and `QwenLlm` are all `BaseModel`s, wired in `__main__.py` as
keyword arguments. `FileReader`, `FileWriter` and `CmmLlmClient` are ABCs, so the
use case is written against abstractions and never imports `llm_sdk`. Swapping
Qwen3 for another model means adding one class, not editing the use case.

**ABCs plus pydantic.** `class JsonReader(BaseModel, FileReader)` combines the two
rather than choosing one: pydantic gives validation and field declaration, the
ABC gives the contract. MRO is legal here because `FileReader` adds no fields.

**JSON-Schema validation of inputs.** The subject warns that input files may be
malformed or missing, and the test files may change during review. Both inputs
are validated against hand-written draft-07 schemas (`PROMPTS_JSON_SCHEMA`,
`FUNCS_JSON_SCHEMA`) before use. The function schema encodes the `fn_` name
pattern, the required keys, `additionalProperties: false`, and an
`if type == array then require items` conditional. A bad input produces a clear
message and exit code 2 instead of a `KeyError` deep in the pipeline.

**Fail loudly, never crash.** Every I/O boundary is wrapped in `try/except` that
prints `[ERROR]: <reason>` and exits with a non-zero code (2 for bad input, 1 for
I/O failures). Files are opened in `with` blocks, so handles cannot leak.

**`numpy` for the argmax.** `np.argmax` is the hot operation — it runs once per
generated token — and it beats a Python `max(..., key=...)` over a ~150k-element
list. `logits` is mutated in place for the banning loop, avoiding a copy per
iteration.

**A regex state machine rather than a schema engine.** The obvious alternative is
to drive decoding from the JSON Schema directly (Outlines' approach: build a
regex/automaton from the schema, map it to a token trie, allow only tokens that
keep the string on a valid path). That is more general and is the right answer
for arbitrary schemas, but it is a lot more machinery. Because the answer
envelope is fixed by the subject — exactly `prompt`, `name`, `parameters` — a
hand-written six-state machine expresses the whole constraint set in six lines and
is fully debuggable. The trade-off is recorded honestly under
[Known limitations](#known-limitations).

**Function choice comes from the LLM.** The subject forbids selecting the
function heuristically. `fn_add_numbers` in the output is the model's argmax token
in state 2, not a lookup table and not a keyword match. The function catalogue
reaches the model only as text inside `<tools>`.

## Performance analysis

Measured on this repository, CPU-only, `Qwen/Qwen3-0.6B`, the 11 prompts and 5
functions in `data/input/`:

| Metric                                          | Result                        |
| ----------------------------------------------- | ----------------------------- |
| Valid, parseable JSON                           | **11/11 (100%)**              |
| Correct function name                           | **11/11 (100%)**              |
| Fully correct call (name **and** all arguments) | **9/11 (81.8%)**              |
| Wall-clock, full run incl. model load           | **~33 s**                     |
| Wall-clock, generation only                     | **~20 s**                     |
| Hardware                                        | x86_64 CPU, `float32`, no GPU |

Comfortably inside the subject's targets: 90%+ function selection and argument
extraction, 100% valid JSON, all prompts under 5 minutes.

The two imperfect entries are both argument-level, not structural:

- _"Replace all vowels in 'Programming is fun' with asterisks"_ produced
  `regex: "\\w+|aeiou"` and `replacement: "*"`, where the catalogue implies
  `aeiou` and `asterisks`. The function was right; the model over-thought the
  regex. This is the classic 0.6B failure mode — the _shape_ is enforced, the
  _content_ is still the model's judgement.

**Why 100% JSON validity is structural, not statistical.** The model is only
consulted in states 0, 2 and 4, and only for the _contents_ of a string. Every
brace, bracket, quote, colon, comma and newline outside those contents is
injected by `StateMachine` from a fixed literal. The state cannot advance until
its regex matches, so a generation that would produce a syntax error cannot
escape the state it is in — it is rejected and the model re-samples. Validity is
therefore a property of the control flow, not of the weights, which is precisely
the point the subject makes about 99%+ reliability from a 0.6B model.

**Cost model.** Forward passes per prompt ≈ number of tokens in the
prompt value + the function name + the parameter block, plus one for EOS
confirmation. The 3 forced states cost zero. This is the optimisation that took
the run from ~90 s to ~33 s; the earlier version re-queried the model for the
structural tokens one at a time.

**Scaling.** Latency is linear in total generated tokens across all prompts and
is independent of the number of functions in the catalogue (they are just prompt
text). A 10× larger test file costs ~10× generation time and nothing in prompt
preparation, since the system prompt is tokenized once outside the per-prompt
loop.

## Challenges faced

**Trailing commas in `parameters`.** The first working version emitted
`"parameters": { "a": 2, "b": 3, }` — valid-looking to a human, invalid JSON. The
model wanted to close the object with a comma, and nothing stopped it. Fixed by
tightening the state-4 regex from `[^\n]*\n$` to `[^\n]*[^,]\n$`, so the token
before the terminating newline is forbidden from being a comma. This was the
single most instructive bug: the fix is one character class, but finding it
required dumping the raw generated tokens and reading the decode.

**Knowing where the answer begins inside the tokenized prompt.** The full
tokenized prompt is system prompt + user prompt + assistant prefix, but
`advance()` has to match a regex against the _answer_ only, not the whole thing.
The prefix contains its own newlines and quotes, which would make the anchored
regexes fire immediately. Solved with `last_index(tokenized_prompt, STC_TK_ID) + 1`
— find the last `<|im_start|>` token and slice from just after it. The state
machine now only ever sees the answer it is producing.

**Knowing when to stop.** EOS id `151658` is Qwen3-specific and was initially
hardcoded deep inside the decode function. Moved to the `QwenLlm` adapter as
`EOT_TK_ID`, resolved once in `model_post_init` by encoding `<|im_end|>`, and
declared on the `CmmLlmClient` ABC so the domain layer asks for "the stop token"
rather than knowing Qwen's vocabulary. The hardcoded `151658` in
`random_constrained_decode` is the remaining leak and is a known cleanup item.

**Speed.** Naive decoding asked the model for every single token, including
braces and keys. Splitting the states into _forced_ (structural literal, no model
call) and _sampled_ (content, argmax) cut the run roughly threefold with no loss
of validity — see the [Design decisions](#design-decisions) section on
`get_state_need`.

**No visible reasoning.** Qwen3 is a hybrid reasoning model and will happily emit
a long `<think>` block before the tool call, which desynchronises every regex.
Suppressed with an explicit empty `<think>\n\n</think>` in `E_PROMPT`, so the
answer starts immediately after it.

## Testing strategy

**Validation on every run.** The strongest guarantee is that the program validates
its own inputs before touching the model, and that the output _cannot_ be
malformed. `JsonReader` checks both files against their JSON Schemas and exits 2
with a readable message on failure. Manual checks performed:

- malformed JSON in either input file → clear error, exit 2, no traceback
- a function definition missing `description` or `returns` → schema rejection
- a function named without the `fn_` prefix → pattern violation
- a non-array where an object list is expected → schema rejection
- missing input file → `[ERROR]: [Errno 2] ...` and exit 2

**Output inspection.** Every run was diffed by hand against the catalogue to
confirm function names and argument names/types, and `json.load`ed to confirm
parseability. The 11-entry result set above is the output of the latest run and
was checked line by line; the two argument-level misses are documented rather than
hidden.

**Unit tests (local only, not submitted).** Per the subject's common
instructions, tests are developed and discarded. They targeted `StateMachine`
in isolation with a fake `CmmLlmClient` — no weights, no model load — asserting
that each state advances only on a match, that `get_state_need` returns forced
tokens for states 1/3/5 and an argmax for 0/2/4, that `advance` does not move on a
mismatched string, and that `random_constrained_decode` returns EOS for any input
logits vector. `JsonReader`/`JsonWriter` were tested against tempfiles for the
happy path and each error path, and `ProcessFunctionCalling` was driven end to end
with a stub client returning a fixed answer, which is what verified the
comma-joining in `_generate_answer`.

**Linting.** `flake8 src/` exits 0. Manual review confirms PEP 257 docstrings on
all public functions and classes, and type hints on all function parameters,
returns and attributes.

## Example usage

```bash
$ uv sync
$ uv run python -m src.call_me_maybe
```

```
[
{
    "prompt":  "What is the sum of 2 and 3?",
    "name": "fn_add_numbers",
    "parameters": {
        "a": 2,
        "b": 3
    }
}
,
{
    "prompt":  "Greet shrek",
    "name": "fn_greet",
    "parameters": {
        "name": "shrek"
    }
}
...
]
```

The odd-looking `,\n` separator and the double space after `"prompt":` are
artifacts of joining per-prompt answers; they are cosmetically untidy but
syntactically valid JSON, and `json.load` handles them without complaint.

Custom paths:

```bash
$ uv run python -m src.call_me_maybe \
    --functions_definition data/input/functions_definition.json \
    --input data/input/function_calling_tests.json \
    --output data/output/function_calling_results.json
```

Under the debugger:

```bash
$ make debug
```

## Project structure

```
src/call_me_maybe/
├── __main__.py            # CLI + composition root
├── domain/
│   ├── interfaces.py      # FileReader, FileWriter, CmmLlmClient (ABCs)
│   ├── constants.py       # paths, JSON Schemas, prompt templates
│   └── services.py        # StateMachine, random_constrained_decode
├── application/
│   └── use_cases.py       # ProcessFunctionCalling
└── infrastructure/
    └── infrastructure.py  # JsonReader, JsonWriter, QwenLlm

data/input/    functions_definition.json, function_calling_tests.json
data/output/   function_calling_results.json   (generated, not committed)
llm_sdk/       Small_LLM_Model wrapper provided by the subject
```

## Known limitations

Documented rather than hidden, since some of these are visible during review:

- **Argument _types_ are not token-level constrained.** Structure is enforced
  strictly, but the model can still choose a string where a number belongs. The
  proper fix is to drive decoding from the JSON Schema with a token trie built
  from the vocabulary file (`get_path_to_vocab_file`), allowing only tokens that
  keep the string schema-valid. `get_vocab()` is already exposed on
  `CmmLlmClient` for exactly this purpose but is not yet used by the state
  machine.
- **EOS id `151658` is still hardcoded** inside `random_constrained_decode`
  instead of using the `EOT_TK_ID` field already declared on the ABC. The two
  disagree as soon as the model changes.
- **`make lint` does not work as written.** `flake8 .` descends into `.venv` and
  pyflakes dies with a `RecursionError`; and `mypy` is not in `pyproject.toml`, so
  `uv run python -m mypy` cannot find it. Both need fixing to satisfy the
  subject's mandatory lint rule — `flake8 src/` passes today, mypy has not been
  run.
- **`data/` is in `.gitignore`**, but the subject asks for `data/input/` to be
  committed and only `output/` to be excluded. The ignore rule should be narrowed
  to `/data/output/`.
- **No committed test suite**, by design per the subject, but it means a reviewer
  cannot run the unit tests described above.
- The `"prompt":` value is echoed back by the model rather than copied
  verbatim from the input file, so a prompt containing quotes or newlines could
  be mangled. Copying the input string directly would be strictly safer.
