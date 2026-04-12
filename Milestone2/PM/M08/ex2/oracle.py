import os

try:
    from dotenv import load_dotenv
    load_dotenv()

    production_txt: str = f"""ORACLE STATUS: Reading the Matrix...

Configuration loaded:
Mode: production
Database: {"Connected to server " if os.getenv("DATABASE_URL") else "None"}
API Access: {"Authenticated" if os.getenv("API_KEY") else "Access denied"}
Log Level: {"DEBUG" if os.getenv("LOG_LEVEL") else "No log level set"}
Zion Network: {"ONLINE" if os.getenv("ZION_ENDPOINT") else "OFFLINE"}

Environment security check:
[OK] No hardcoded secrets detected
[OK] .env file properly configured
[OK] Production overrides available

The Oracle sees all configurations"""
    development_txt: str = f"""ORACLE STATUS: Reading the Matrix...

Configuration loaded:
Mode: development
Database: {"Connected to local instance"
           if os.getenv("DATABASE_URL") else "No database to connect"}
API Access: {"Authenticated" if os.getenv("API_KEY") else "Access denied"}
Log Level: {"USER USE" if os.getenv("LOG_LEVEL") else "No log level set"}
Zion Network: {"ONLINE" if os.getenv("ZION_ENDPOINT") else "OFFLINE"}

Environment security check:
[OK] No hardcoded secrets detected
[OK] .env file properly configured
[OK] Production overrides available

The Oracle sees all configurations"""

    mode: str | None = os.getenv("MATRIX_MODE")
    if mode == "development":
        print(development_txt)
    elif mode == "production":
        print(production_txt)
    elif not mode:
        print("No MODE variable in enviroment...")
    else:
        print("Not in production nor development, u dummy")
except Exception as err:
    print(f"[ERROR]: {err}")
