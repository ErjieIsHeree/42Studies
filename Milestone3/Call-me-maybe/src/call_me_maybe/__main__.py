import sys
import argparse

from call_me_maybe.infrastructure import JsonReader, JsonWriter, QwenLlm
from call_me_maybe.application import ProcessFunctionCalling
from call_me_maybe.domain import (
    FUNCS_FILE,
    PROMPTS_FILE,
    OUTPUT_FILE,
    PROMPTS_JSON_SCHEMA,
    FUNCS_JSON_SCHEMA
)


def read_args():
    """This method reads the possible args to this program

    Raises:
        Something if args contain any other unwanted thing"""
    parser = argparse.ArgumentParser()

    parser.add_argument(
        "--functions_definition",
        required=False,
        type=str,
        default=FUNCS_FILE
    )
    parser.add_argument(
        "--input",
        required=False,
        type=str,
        default=PROMPTS_FILE
    )
    parser.add_argument(
        "--output",
        required=False,
        type=str,
        default=OUTPUT_FILE
    )

    return parser.parse_args()


def main():
    """This function uses a Function Calling application applying the
    Small_LLM_Model from a 42Next project called Call Me Maybe"""

    try:
        args = read_args()
    except Exception as err:
        print(err)
        sys.exit(1)

    FUNCS_FILE = args.functions_definition
    PROMPTS_FILE = args.input
    OUTPUT_FILE = args.output

    cmm_ai_use_case = ProcessFunctionCalling(
        prompt_repository=JsonReader(
            file_path=PROMPTS_FILE, json_schema=PROMPTS_JSON_SCHEMA),
        func_defs_repository=JsonReader(
            file_path=FUNCS_FILE, json_schema=FUNCS_JSON_SCHEMA),
        llm_client=QwenLlm(),
        writer=JsonWriter(file_path=OUTPUT_FILE)
    )

    cmm_ai_use_case.execute()


if __name__ == "__main__":
    main()
