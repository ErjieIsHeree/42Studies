import argparse

from call_me_maybe.infrastructure import JsonReader, JsonWriter, QwenLlm
from call_me_maybe.infrastructure.application import ProcessFunctionCalling


def main():     # TODO getting user args and creating json_schemas
    """This function uses a Function Calling application applying the
    Small_LLM_Model from a 42Next project called Call Me Maybe"""

    FUNC_CALL_FILE = "data/input/function_calling_tests.json"
    FUNC_DEF_FILE = "data/input/functions_definition.json"
    OUTPUT_FILE = "data/output/function_calling_results.json"
    a = {}

    cmm_ai_use_case = ProcessFunctionCalling(
        JsonReader(file_path=FUNC_CALL_FILE, json_schema=a),
        JsonReader(file_path=FUNC_DEF_FILE, json_schema=a),
        QwenLlm(),
        JsonWriter(file_path=OUTPUT_FILE)
    )

    cmm_ai_use_case.execute()


if __name__ == "__main__":
    main()
