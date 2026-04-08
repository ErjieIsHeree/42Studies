import typing
from typing import Any
import abc


class DataProcessor(abc.ABC):
    def __init__(self) -> None:
        self.oldest: int = -1
        self.ingest_l: list[tuple[int, str]] = []
        return

    @abc.abstractmethod
    def validate(self, data: Any) -> bool: ...

    @abc.abstractmethod
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


class ExportPlugin(typing.Protocol):
    def process_output(self, data: list[tuple[int, str]]) -> None: ...
    pass


class CSVExportPlugin():
    def process_output(self, data: list[tuple[int, str]]) -> None:
        print("CSV Output:")
        csv_format: str = ""
        for dat in data:
            csv_format += f"{dat[1]},"
            pass
        print(csv_format[:-1])
        return
    pass


class JSONExportPlugin():
    def process_output(self, data: list[tuple[int, str]]) -> None:
        print("JSON Output:")
        json_format: str = "{"
        for dat in data:
            json_format += f"\"item_{dat[0]}\": \"{dat[1]}\","
            pass
        json_format = json_format[:-1]
        json_format += "}"
        print(json_format)
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
            print(f"Text Processor: total {self.text_proc.oldest + 1} items"
                  f" processed, remaining {len(self.text_proc.ingest_l)} on pr"
                  "ocessor")
            pass
        if self.log_proc:
            print(f"Log Processor: total {self.log_proc.oldest + 1} items "
                  f"processed, remaining {len(self.log_proc.ingest_l)} on proc"
                  "essor")
            pass
        return

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        outputs: list[Any] = []
        if self.numeric_proc:
            for i in range(min(nb, len(self.numeric_proc.ingest_l))):
                outputs += [self.numeric_proc.output()]
            plugin.process_output(outputs)
            pass
        outputs = []
        if self.text_proc:
            for i in range(min(nb, len(self.text_proc.ingest_l))):
                outputs += [self.text_proc.output()]
            plugin.process_output(outputs)
            pass
        outputs = []
        if self.log_proc:
            for i in range(min(nb, len(self.log_proc.ingest_l))):
                outputs += [self.log_proc.output()]
            plugin.process_output(outputs)
            pass
        return
    pass


print("=== Code Nexus - Data Pipeline ===\n")

print("Initialize Data Stream...\n")
data_stream: DataStream = DataStream()

print("== DataStream statistics ==")
data_stream.print_processors_stats()

print("\nRegistering Processors\n")
data_stream.register_processor(NumericProcessor())
data_stream.register_processor(TextProcessor())
data_stream.register_processor(LogProcessor())

print("Send first batch of data on stream: ['Hello world', [3.14, -1, 2.71], ["
      "{'log_level': 'WARNING', 'log_message': 'Telnet access! Use ssh instead"
      "'}, {'log_level': 'INFO', 'log_message': 'User wil is connected'}], 42,"
      " ['Hi', 'five']]\n")
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

print("\nSend 3 processed data from each processor to a CSV plugin:")
data_stream.output_pipeline(3, CSVExportPlugin())

print("\n== DataStream statistics ==")
data_stream.print_processors_stats()

print("\nSend another batch of data: [21, ['I love AI', 'LLMs are wonderful', "
      "'Stay healthy'], [{'log_level': 'ERROR', 'log_message': '500 server cra"
      "sh'}, {'log_level': 'NOTICE', 'log_message': 'Certificate expires in 10"
      " days'}], [32, 42, 64, 84, 128, 168], 'World hello']")
data_stream.process_stream([
    21,
    ['I love AI', 'LLMs are wonderful', 'Stay healthy'],
    [{'log_level': 'ERROR', 'log_message': '500 server crash'},
     {'log_level': 'NOTICE', 'log_message': 'Certificate expires in 10 days'}],
    [32, 42, 64, 84, 128, 168],
    'World hello'
])

print("\n== DataStream statistics ==")
data_stream.print_processors_stats()

print("\nSend 5 processed data from each processor to a JSON plugin:")
data_stream.output_pipeline(5, JSONExportPlugin())

print("\n== DataStream statistics ==")
data_stream.print_processors_stats()
