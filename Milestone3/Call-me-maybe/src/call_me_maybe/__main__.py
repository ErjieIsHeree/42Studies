# import sys
from llm_sdk import Small_LLM_Model


def get_args() -> dict[str, str]:
    """Retreaves """
    # args: dict[str, str] = {}

    # if len(sys.argv[1:]) % 2 != 0 or len(sys.argv[1:]) > 6:
    #     raise 

    # for i, arg in enumerate(sys.argv[1:]):
    #     if i % 2 != 0:
    #         arg.startswith("--")
    #     pass

    return {
        "functions_definition": "data/input/functions_definition.json",
        "input": "data/input/function_calling_tests.json",
        "output": "data/output/function_calls.json"
    }


def main() -> None:
    magician = Small_LLM_Model()
    print(magician.encode("HOla"))
    # magician.get_logits_from_input_ids()
    # magician.get_path_to_vocab_file()


if __name__ == "__main__":
    main()
