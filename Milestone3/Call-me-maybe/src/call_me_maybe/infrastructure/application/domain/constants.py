PROMPTS_FILE = "data/input/function_calling_tests.json"
FUNCS_FILE = "data/input/functions_definition.json"
OUTPUT_FILE = "data/output/function_calling_results.json"

# TODO review the schemas
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

OUTPUT_EXAMPLE = """[
    {
        "prompt": "What is the sum of 2 and 3?",
        "name": "fn_add_numbers",
        "parameters": {"a": 2.0, "b": 3.0}
    },
    {
        "prompt": "Reverse the string 'hello'",
        "name": "fn_reverse_string",
        "parameters": {"s": "hello"}
    }
]"""
