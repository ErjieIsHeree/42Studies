
from call_me_maybe.infrastructure import JsonReader, JsonWriter, QwenLlm
from call_me_maybe.infrastructure.application import ProcessFunctionCalling

from llm_sdk import Small_LLM_Model  # !! cHECK THIS SHIT


def main():
    FUNC_CALL_FILE = "data/input/function_calling_tests.json"
    FUNC_DEF_FILE = "data/input/functions_definition.json"
    OUTPUT_FILE = "data/output/function_calling_results.json"

    cmm_ai_use_case = ProcessFunctionCalling(
        JsonReader(FUNC_CALL_FILE),
        JsonReader(FUNC_DEF_FILE),
        QwenLlm(),
        JsonWriter(OUTPUT_FILE)
    )

    cmm_ai_use_case.execute()


if __name__ == "__main__":
    main()
