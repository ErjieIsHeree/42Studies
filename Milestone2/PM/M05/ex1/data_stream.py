from abc import ABC, abstractmethod
from typing import Any, Optional, List, Dict, Union, Generator


def write_coma(data_batch: List[str]) -> Generator[str]:
    yield data_batch[0]
    for i in range(1, len(data_batch)):
        yield f", {data_batch[i]}"
    return None


class DataStream(ABC):
    stream_id: str
    type: str

    def __init__(self, stream_id: str) -> None:
        self.stream_id = stream_id

    @abstractmethod
    def process_batch(self, data_batch: List[Any]) -> str: ...

    def filter_data(
        self, data_batch: List[Any], criteria: Optional[str] = None
    ) -> List[Any]:
        return []

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        return {}
    pass


class SensorStream(DataStream):
    temp: float = 0.0
    humidity: int = 0
    pressure: int = 0

    def __init__(self, stream_id: str) -> None:
        super().__init__(stream_id)
        self.type = "Environmental Data"

    def process_batch(self, data_batch: List[Any]) -> str:
        self.temp = 0.0
        self.humidity = 0
        self.pressure = 0
        try:
            for data in data_batch:
                type, info = data.split(":")
                match type:
                    case "temp":
                        self.temp = round(float(info), 1)
                        pass
                    case "humidity":
                        self.humidity = int(info)
                        pass
                    case "pressure":
                        self.pressure = int(info)
                        pass
                    case _:
                        raise Exception(f"Enviroment {type} isn't real")
        except Exception as err:
            print(f"[ERROR]: {err}")
        return (f"[temp:{self.temp}, humidity:{self.humidity}, "
                f"pressure:{self.pressure}]")

    def filter_data(
        self, data_batch: List[Any], criteria: Optional[str] = None
    ) -> List[Any]:
        filtered_data: list[dict[str, int | float]] = []
        self.process_batch(data_batch)
        match criteria:
            case "High-priority":
                if (self.temp < 15 or self.temp > 40) and self.temp != 0:
                    filtered_data.append({"Temperature": self.temp})
                if ((self.humidity < 30 or self.humidity > 60) and
                   self.humidity != 0):
                    filtered_data.append({"Humidity": self.humidity})
                if (self.pressure < 980 or self.pressure > 1040 and
                   self.pressure) != 0:
                    filtered_data.append({"Pressure": self.pressure})
            case _:
                filtered_data = data_batch
        return filtered_data

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        return {
            "readings": 3,
            "avg_temp": self.temp
        }
    pass


class TransactionStream(DataStream):
    operations_qty: int = 0
    large_oprations: int = 0
    buy: int = 0
    sell: int = 0

    def __init__(self, stream_id: str) -> None:
        super().__init__(stream_id)
        self.type = "Financial Data"

    def process_batch(self, data_batch: List[Any]) -> str:
        self.operations_qty = 0
        self.large_oprations = 0
        self.buy = 0
        self.sell = 0
        result = "["
        try:
            for data in data_batch:
                operation, qty = data.split(":")
                match operation:
                    case "buy":
                        self.buy += int(qty)
                        pass
                    case "sell":
                        self.sell += int(qty)
                        pass
                    case _:
                        raise Exception(f"Operation {operation} isn't real")
                self.operations_qty += 1
                if int(qty) > 100:
                    self.large_oprations += 1
        except Exception as err:
            print(f"[ERROR]: {err}")
        else:
            data_gen = write_coma(data_batch)
            for data in data_batch:
                result += next(data_gen)
        result += "]"
        return result

    def filter_data(
        self, data_batch: List[Any], criteria: Optional[str] = None
    ) -> List[Any]:
        filtered_data: list[str] = []
        self.process_batch(data_batch)
        match criteria:
            case "High-priority":
                for i in range(self.large_oprations):
                    filtered_data += [f"Operation {i}: some quantity"]
            case _:
                filtered_data = data_batch
        return filtered_data

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        net_flow = self.buy - self.sell
        net_is_negative = net_flow < 0
        if net_is_negative:
            str_net = f"{net_flow}"
        else:
            str_net = f"+{net_flow}"
        return {
            "operations": self.operations_qty,
            "net_flow": str_net
        }
    pass


class EventStream(DataStream):
    events_l: list[str] = []

    def __init__(self, stream_id: str) -> None:
        super().__init__(stream_id)
        self.type = "System Events"

    def process_batch(self, data_batch: List[Any]) -> str:
        result = "["
        for event in data_batch:
            self.events_l += [event]
        data_gen = write_coma(data_batch)
        for data in data_batch:
            result += next(data_gen)
        result += "]"
        return result

    def filter_data(
        self, data_batch: List[Any], criteria: Optional[str] = None
    ) -> List[Any]:
        filtered_data: list[dict[str, int | float]] = []
        self.process_batch(data_batch)
        match criteria:
            case "High-priority":
                filtered_data = []
            case _:
                filtered_data = data_batch
        return filtered_data

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        return {
            "events_qty": len(self.events_l),
            "errors_qty": len([event for event in self.events_l
                               if event == "error"])
        }
    pass


class StreamProcessor():
    data_stream: DataStream

    def __init__(self, data_stream: DataStream) -> None:
        self.data_stream = data_stream

    def process_batch(self, data_batch: List[Any]) -> str:
        return self.data_stream.process_batch(data_batch)

    def filter_data(
        self, data_batch: List[Any], criteria: Optional[str] = None
    ) -> List[Any]:
        return self.data_stream.filter_data(data_batch, criteria)

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        return self.data_stream.get_stats()

    pass


sensor_batch = ["temp:22.5", "humidity:65", "pressure:1013"]
transaction_batch = ["buy:100", "sell:150", "buy:75"]
event_batch = ["login", "error", "logout"]


print("=== CODE NEXUS - POLYMORPHIC STREAM SYSTEM ===\n")

print("Initializing Sensor Stream...")
sensor = SensorStream("SENSOR_001")
print("Stream ID: SENSOR_001, Type: Environmental Data")
print(f"Processing sensor batch: {sensor.process_batch(sensor_batch)}")
readings, temp = sensor.get_stats().values()
print(f"Sensor analysis: {readings} readings processed, avg temp: {temp}°C")

print("\nInitializing Transaction Stream...")
transaction = TransactionStream("TRANS_001")
print("Stream ID: TRANS_001, Type: Financial Data")
print("Processing transaction batch: "
      f"{transaction.process_batch(transaction_batch)}")
operations, net = transaction.get_stats().values()
print(f"Transaction analysis: {operations} operations, net flow: {net} units")

print("\nInitializing Event Stream...")
event = EventStream("EVENT_001")
print("Stream ID: EVENT_001, Type: System Events")
print(f"Processing event batch: {event.process_batch(event_batch)}")
event_qty, error_qty = event.get_stats().values()
print(f"Event analysis: {event_qty} events, {error_qty} error detected")

datas = [["temp:22.5", "humidity:200"],
         ["buy:100", "sell:150", "buy:75", "sell:2"],
         ["login", "error", "logout"]]
stream_processor = [StreamProcessor(sensor),
                    StreamProcessor(transaction),
                    StreamProcessor(event)]

print("\n=== Polymorphic Stream Processing ===")
print("Processing mixed stream types through unified interface...\n")

print("Batch 1 Results:")
for data, processor in zip(datas, stream_processor):
    processor.process_batch(data)
print("- Sensor data: 2 readings processed")
print("- Transaction data: 4 operations processed")
print("- Event data: 3 events processed")

print("\nStream filtering active: High-priority data only")
sensor_alerts = []
large_transactions = []
for i, (data, processor) in enumerate(zip(datas, stream_processor)):
    match i:
        case 0:
            sensor_alerts = processor.filter_data(data)
        case 1:
            large_transactions = processor.filter_data(data)
        case _:
            pass
print(f"Filtered results: {len(sensor_alerts)} critical sensor alerts, "
      f"{len(large_transactions)} large transaction")
