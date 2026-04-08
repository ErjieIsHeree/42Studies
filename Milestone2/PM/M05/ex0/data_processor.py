from typing import Any
import abc


class DataProcessor(abc.ABC):
    def __init__(self) -> None:
        self.oldest: int = -1
        self.ingest_l: list[tuple[int, str]] = []
        pass

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
        pass
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
        pass
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
        pass
    pass


print("""=== Code Nexus - Data Processor ===\n""")

n_processor: NumericProcessor = NumericProcessor()
exception: Exception = Exception()
try:
    n_processor.ingest("foo")
except Exception as err:
    exception = err
    pass
n_processor.ingest([1, 2, 3, 4, 5])
n_value0: tuple[int, str] = n_processor.output()
n_value1: tuple[int, str] = n_processor.output()
n_value2: tuple[int, str] = n_processor.output()
print(f"""Testing Numeric Processor...
Trying to validate input '42': {n_processor.validate(42)}
Trying to validate input 'Hello': {n_processor.validate("Hello")}
Test invalid ingestion of string 'foo' without prior validation:
Got exception: {exception}
Processing data: [1, 2, 3, 4, 5]
Extracting 3 values...
Numeric value {n_value0[0]}: {n_value0[1]}
Numeric value {n_value1[0]}: {n_value1[1]}
Numeric value {n_value2[0]}: {n_value2[1]}\n""")

t_processor: TextProcessor = TextProcessor()
t_processor.ingest(['Hello', 'Nexus', 'World'])
t_value0: tuple[int, str] = t_processor.output()
print(f"""Testing Text Processor...
Trying to validate input '42': {t_processor.validate(42)}
Processing data: ['Hello', 'Nexus', 'World']
Extracting 1 value...
Text value {t_value0[0]}: {t_value0[1]}\n""")

l_processor: LogProcessor = LogProcessor()
l_processor.ingest([
    {'log_level': 'NOTICE', 'log_message': 'Connection to server'},
    {'log_level': 'ERROR', 'log_message': 'Unauthorized access!!'}
])
l_value0: tuple[int, str] = l_processor.output()
l_value1: tuple[int, str] = l_processor.output()
print(f"""Testing Log Processor...
Trying to validate input 'Hello': {l_processor.validate("Hello")}
Processing data: [{{'log_level': 'NOTICE', 'log_message': 'Connection to server
'}}, {{'log_level': 'ERROR', 'log_message': 'Unauthorized access!!'}}]
Extracting 2 values...
Log entry {l_value0[0]}: {l_value0[1]}
Log entry {l_value1[0]}: {l_value1[1]}""")
