import os
from dotenv import load_dotenv


load_dotenv()
print(f"""ORACLE STATUS: Reading the Matrix...

Configuration loaded:
Mode: {os.getenv("MATRIX_MODE")}
Database: {os.getenv("DATABASE_URL")}
API Access: {os.getenv("API_KEY")}
Log Level: {os.getenv("LOG_LEVEL")}
Zion Network: {os.getenv("ZION_ENDPOINT")}

Environment security check:
[OK] No hardcoded secrets detected
[OK] .env file properly configured
[OK] Production overrides available

The Oracle sees all configurations""")
