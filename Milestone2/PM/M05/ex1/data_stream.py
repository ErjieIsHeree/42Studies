import typing
from typing import Any
from abc import ABC, abstractmethod


class DataProcessor(ABC):
    def __init__(self) -> None:
        self.oldest: int = -1
        self.ingest_l: list[tuple[int, str]] = []
        return

    @abstractmethod
    def validate(self, data: Any) -> bool: ...

    @abstractmethod
    def ingest(self, data: Any) -> None: ...

    def output(self) -> tuple[int, str]:
        return self.ingest_l.pop(0)

    pass


class NumericProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, int | float):
            return True
        if isinstance(data, list):
            for l_data in data:
                if not isinstance(l_data, int | float):
                    return False
            return True
        return False

    def ingest(self, data: Any) -> None:
        if not self.validate(data):
            raise ValueError("Improper numeric data")
        if isinstance(data, float | int):
            data = [data]

        for item in data:
            self.oldest += 1
            self.ingest_l += [(self.oldest, str(item))]
        return
    pass


class TextProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, str):
            return True
        if isinstance(data, list):
            for item in data:
                if not isinstance(item, str):
                    return False
            return True
        return False

    def ingest(self, data: Any) -> None:
        if not self.validate(data):
            raise ValueError("Improper text data")
        if isinstance(data, str):
            data = [data]

        for item in data:
            self.oldest += 1
            self.ingest_l += [(self.oldest, item)]
        return
    pass


class LogProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, dict):
            return True
        if isinstance(data, list):
            for item in data:
                if not isinstance(item, dict):
                    return False
            return True
        return False

    def ingest(self, data: Any) -> None:
        if not self.validate(data):
            raise ValueError("Improper log data")
        if isinstance(data, dict):
            data = [data]

        for item in data:
            self.oldest += 1
            self.ingest_l += [(self.oldest, (f"{item["log_level"]}: "
                                             f"{item["log_message"]}"))]
        return
    pass


class DataStream():
    def __init__(self) -> None:
        self.numeric_proc: NumericProcessor | None = None
        self.text_proc: TextProcessor | None = None
        self.log_proc: LogProcessor | None = None
        return

    def register_processor(self, proc: DataProcessor) -> None:
        match proc:
            case NumericProcessor():
                self.numeric_proc = proc
                pass
            case TextProcessor():
                self.text_proc = proc
                pass
            case LogProcessor():
                self.log_proc = proc
                pass
        return

    def process_stream(self, stream: list[typing.Any]) -> None:
        for data in stream:
            if self.numeric_proc and self.numeric_proc.validate(data):
                self.numeric_proc.ingest(data)
            elif self.text_proc and self.text_proc.validate(data):
                self.text_proc.ingest(data)
            elif self.log_proc and self.log_proc.validate(data):
                self.log_proc.ingest(data)
            else:
                print("DataStream error - Can't process element in stream: "
                      f"{data}")
        return

    def print_processors_stats(self) -> None:
        if not self.numeric_proc and not self.text_proc and not self.log_proc:
            print("No processor found, no data")
            return
        if self.numeric_proc:
            print(f"Numeric Processor: total {self.numeric_proc.oldest + 1} it"
                  f"ems processed, remaining {len(self.numeric_proc.ingest_l)}"
                  " on processor")
            pass
        if self.text_proc:
            print(f"Numeric Processor: total {self.text_proc.oldest + 1} items"
                  f" processed, remaining {len(self.text_proc.ingest_l)} on pr"
                  "ocessor")
            pass
        if self.log_proc:
            print(f"Numeric Processor: total {self.log_proc.oldest + 1} items "
                  f"processed, remaining {len(self.log_proc.ingest_l)} on proc"
                  "essor")
            pass
        return
    pass


print("=== Code Nexus - Data Stream ===\n")


print("Initialize Data Stream...")
data_stream: DataStream = DataStream()

print("== DataStream statistics ==")
data_stream.print_processors_stats()

print("\nRegistering Numeric Processor\n")
data_stream.register_processor(NumericProcessor())

print("Send first batch of data on stream: ['Hello world', [3.14, -1, 2.71], ["
      "{'log_level': 'WARNING', 'log_message': 'Telnet access! Use ssh instead"
      "'}, {'log_level': 'INFO', 'log_message': 'User wil is connected'}], 42,"
      " ['Hi', 'five']]")
data_stream.process_stream([
    'Hello world',
    [3.14, -1, 2.71],
    [{'log_level': 'WARNING', 'log_message': 'Telnet access! Use ssh instead'},
     {'log_level': 'INFO', 'log_message': 'User wil is connected'}],
    42,
    ['Hi', 'five']
])
print("== DataStream statistics ==")
data_stream.print_processors_stats()

print("\nRegistering other data processors")
data_stream.register_processor(TextProcessor())
data_stream.register_processor(LogProcessor())

print("Send the same batch again")
data_stream.process_stream([
    'Hello world',
    [3.14, -1, 2.71],
    [{'log_level': 'WARNING', 'log_message': 'Telnet access! Use ssh instead'},
     {'log_level': 'INFO', 'log_message': 'User wil is connected'}],
    42,
    ['Hi', 'five']
])
print("== DataStream statistics ==")
data_stream.print_processors_stats()

print("\nConsume some elements from the data processors: Numeric 3, Text 2, Lo"
      "g 1")
if data_stream.numeric_proc:
    data_stream.numeric_proc.output()
    data_stream.numeric_proc.output()
    data_stream.numeric_proc.output()
if data_stream.text_proc:
    data_stream.text_proc.output()
    data_stream.text_proc.output()
if data_stream.log_proc:
    data_stream.log_proc.output()
print("== DataStream statistics ==")
data_stream.print_processors_stats()
