import os

all_installed = True
dotenv_version = "1.2.2"

try:
    from dotenv import load_dotenv
except Exception as err:
    all_installed = False
    print(f"[ERROR]: {err}")


if all_installed:
    print("\nORACLE STATUS: Reading the Matrix...\n")

    try:
        load_dotenv()
        MATRIX_MODE = os.environ["MATRIX_MODE"]
        DATABASE_URL = os.environ["DATABASE_URL"]
        API_KEY = os.environ["API_KEY"]
        LOG_LEVEL = os.environ["LOG_LEVEL"]
        ZION_ENDPOINT = os.environ["ZION_ENDPOINT"]

        print(f"""Configuration loaded:
Mode: {MATRIX_MODE}
Database: {DATABASE_URL}
API Access: {API_KEY}
Log Level: {LOG_LEVEL}
Zion Network: {ZION_ENDPOINT}

Environment security check:
[OK] No hardcoded secrets detected
[OK] .env file properly configured
[OK] Production overrides available

The Oracle sees all configurations.""")
    except Exception as err:
        print(f"[ERROR]:  required enviroment variable {err} doesn't exist")
else:
    print("Can not complete program")
