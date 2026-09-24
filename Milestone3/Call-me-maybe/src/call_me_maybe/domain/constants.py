PROMPTS_FILE = "data/input/function_calling_tests.json"
FUNCS_FILE = "data/input/functions_definition.json"
OUTPUT_FILE = "data/output/function_calling_results.json"

PROMPTS_JSON_SCHEMA = {
    "$schema": "http://json-schema.org/draft-07/schema#",
    "title": "PromptList",
    "description": "List of prompts for a function calling process",
    "type": "array",
    "items": {
        "type": "object",
        "properties": {
            "prompt": {
                "type": "string",
                "description": "Users prompt",
                "minLength": 1
            }
        },
        "required": ["prompt"],
        "additionalProperties": False
    },
    "minItems": 1
}

FUNCS_JSON_SCHEMA = {
    "$schema": "http://json-schema.org/draft-07/schema#",
    "title": "FunctionDefinitionList",
    "type": "array",
    "items": {
        "type": "object",
        "properties": {
            "name": {
                "type": "string",
                "pattern": "^fn_[a-zA-Z0-9_]+$"
            },
            "description": {
                "type": "string"
            },
            "parameters": {
                "type": "object",
                "additionalProperties": {
                    "$ref": "#/definitions/typeSchema"
                }
            },
            "returns": {
                "$ref": "#/definitions/typeSchema"
            }
        },
        "required": ["name", "description", "parameters", "returns"],
        "additionalProperties": False
    },
    "definitions": {
        "typeSchema": {
            "type": "object",
            "properties": {
                "type": {
                    "type": "string",
                    "enum": [
                        "string",
                        "number",
                        "integer",
                        "boolean",
                        "array",
                        "object"
                    ]
                },
                "items": {
                    "$ref": "#/definitions/typeSchema"
                }
            },
            "required": ["type"],
            "additionalProperties": False,
            "if": {
                "properties": {"type": {"const": "array"}}
            },
            "then": {
                "required": ["type", "items"]
            }
        }
    }
}

S_PROMPT = """<|im_start|>system
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
"""

ANSWER_EXAMPLE = """{
    "prompt": <user-prompt>,
    "name": <function-name>,
    "parameters": <args-json-object>
}"""

E_PROMPT = """<|im_end|>
<|im_start|>assistant"""
