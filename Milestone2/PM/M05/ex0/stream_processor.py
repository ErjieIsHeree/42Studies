from abc import ABC, abstractmethod
from typing import Any
import re


class DataProcessor(ABC):
    @abstractmethod
    def process(self, data: Any) -> str: ...

    @abstractmethod
    def validate(self, data: Any) -> bool: ...

    def format_output(self, result: str) -> str:
        return result
    pass


class NumericProcessor(DataProcessor):
    def process(self, data: Any) -> str:
        quantity: int = 0
        total: int = 0
        average: float = 0.0

        if not self.validate(data):
            return ""

        data = [data] if isinstance(data, int) else data

        quantity = len(data)
        total = sum(data)
        average = round(total / quantity, 1)
        return f"{quantity}-{total}-{average}"

    def validate(self, data: Any) -> bool:
        if isinstance(data, int):
            return True
        return (isinstance(data, (tuple, set, list))
                and all(isinstance(d, int) for d in data))

    def format_output(self, result: str) -> str:
        if re.match(r"^\d+-\d+-\d+.\d$", result) is None:
            return ""
        qty, tot, avg = result.split("-")
        return f"Output: Processed {qty} numeric values, sum={tot}, avg={avg}"
    pass


class TextProcessor(DataProcessor):
    def process(self, data: Any) -> str:
        if self.validate(data):
            return ""

        words = data.split(" ")
        length = len([c for word in words for c in word])

        return f"{len(words)}-{length}"

    def validate(self, data: Any) -> bool:
        return isinstance(data, str)

    def format_output(self, result: str) -> str:
        if re.match(r"^\d+-\d+$", result) is None:
            return ""
        total_words, lenght = result.split("-")
        return (f"Output: Processed text: {lenght} characters, {total_words} "
                "words")
    pass


class LogProcessor(DataProcessor):
    def process(self, data: Any) -> str:
        if not self.validate(data):
            return ""
        type, log = data.split(": ")
        return f"{type}-{log}"

    def validate(self, data: Any) -> bool:
        if not isinstance(data, str):
            return False
        if re.match(r"^(ERROR|INFO): [a-zA-Z ]+$", data) is None:
            return False
        return True

    def format_output(self, result: str) -> str:
        if re.match(r"^(ERROR|INFO)-[\w ]+$", result) is None:
            return ""
        type, log = result.split("-")
        if type == "ERROR":
            return f"Output: [ALERT] ERROR level detected: {log}"
        else:
            return f"Output: [INFO] INFO level detected: {log}"
    pass


numbers = [1, 2, 3, 4, 5]
text = "Hello Nexus World"
log = "ERROR: Connection timeout"

print("=== CODE NEXUS - DATA PROCESSOR FOUNDATION ===\n")

print("Initializing Numeric Processor...")
n_processor = NumericProcessor()
print(f"Processing data: {numbers}")
n_processor.process(numbers)
n_processor.validate(numbers)
print("Validation: Numeric data verified")
print(n_processor.format_output(n_processor.process(numbers)))

print("\nInitializing Text Processor...")
txt_processor = TextProcessor()
print(f"Processing data: {text}")
txt_processor.process(text)
txt_processor.validate(text)
print("Validation: Text data verified")
print(txt_processor.format_output(txt_processor.process(text)))

print("\nInitializing Log Processor...")
log_processor = LogProcessor()
print(f"Processing data: {log}")
log_processor.process(log)
log_processor.validate(log)
print("Validation: Log entry verified")
print(log_processor.format_output(log_processor.process(log)))

processors: list[DataProcessor] = [
    NumericProcessor(),
    TextProcessor(),
    LogProcessor()
]

info: list = [
    [1, 2, 3],
    "Hello Nexusss",
    "INFO: System ready"
]

print("\n=== Polymorphic Processing Demo ===\n")
print("Processing multiple data types through same interface...")
for processor, data in zip(processors, info):
    print(processor.format_output(processor.process(data)))
print("\nFoundation systems online. Nexus ready for advanced streams.")
