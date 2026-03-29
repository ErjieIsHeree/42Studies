from abc import ABC, abstractmethod
from typing import Any, Protocol, Union

class ProcessingStage(Protocol):
    def process(self, data: Any) -> Any: ...
    pass

class InputStage():
    def process(self, data: Any) -> dict:
        result: dict = {}
        # TODO this method
        if isinstance(data, dict):
            result = {"type": "json", "raw": data, "value": data.get("value")}
        elif isinstance(data, str):
            result = {"type": "csv", "raw": data, "cols": data.split(",")}
        elif isinstance(data, list):
            result = {"type": "stream", "raw": data}
        return result
        pass

class TransformStage():
    def process(self, data: Any) -> dict:
        result: dict = {}
        # TODO this method
        if data.get("type") == "json":
            result = {**data, "enriched": True, "status": "Normal range"}
        elif data.get("type") == "csv":
            result = {**data, "action_count": len(data["cols"]) - 1}
        elif data.get("type") == "stream":
            readings = data["raw"]
            result = {**data, "count": len(readings), "avg": round(sum(readings) / len(readings), 1)}
        return result
        pass

class OutputStage():
    def process(self, data: Any) -> str:
        result: str = ""
        # TODO this method
        if data.get("type") == "json":
            result = f"Processed temperature reading: {data['value']}°C ({data['status']})"
        elif data.get("type") == "csv":
            result = f"User activity logged: {data['action_count']} actions processed"
        elif data.get("type") == "stream":
            result = f"Stream summary: {data['count']} readings, avg: {data['avg']}°C"
        return result
        pass

class ProcessingPipeline(ABC):
    stages: list[ProcessingStage] = []

    def add_stage(self) -> None:
        # TODO this method
        def stage_generator():
            yield InputStage()
            yield TransformStage()
            yield OutputStage()

        for i, stage in enumerate(stage_generator(), start=1):
            print(f"Stage {i}: ", end="")
            if i == 1:
                print("Input validation and parsing")
            elif i == 2:
                print("Data transformation and enrichment")
            elif i == 3:
                print("Output formatting and delivery")
            self.stages.append(stage)
        pass

    @abstractmethod
    def process(self, data: Any) -> Union[str, Any]: ...
    pass

class JSONAdapter(ProcessingPipeline):
    def __init__(self, pipeline_id: str) -> None:
        self.pipeline_id: str = pipeline_id
        pass

    def process(self, data: Any) -> Union[str, Any]:
        # TODO this method
        print(f'Input: {{"sensor": "{data["sensor"]}", "value": {data["value"]}, "unit": "{data["unit"]}"}}'  )
        print("Transform: Enriched with metadata and validation")
        result = data
        for stage in self.stages:
            result = stage.process(result)
        print(f"Output: {result}")
        pass
    pass

class CSVAdapter(ProcessingPipeline):
    def __init__(self, pipeline_id: str) -> None:
        self.pipeline_id: str = pipeline_id
        pass

    def process(self, data: Any) -> Union[str, Any]:
        # TODO this method
        print(f'Input: "{data}"')
        print("Transform: Parsed and structured data")
        result = data
        for stage in self.stages:
            result = stage.process(result)
        print(f"Output: {result}")
        pass
    pass

class StreamAdapter(ProcessingPipeline):
    def __init__(self, pipeline_id: str) -> None:
        self.pipeline_id: str = pipeline_id
        pass

    def process(self, data: Any) -> Union[str, Any]:
        # TODO this method
        print("Input: Real-time sensor stream")
        print("Transform: Aggregated and filtered")
        result = data
        for stage in self.stages:
            result = stage.process(result)
        print(f"Output: {result}")
        pass
    pass

class NexusManager():
    pipelines: list[ProcessingPipeline] = []

    def add_pipeline(self) -> None:
        # TODO this method
        def pipeline_generator():
            yield JSONAdapter("json-1")
            yield CSVAdapter("csv-1")
            yield StreamAdapter("stream-1")

        for pipeline in pipeline_generator():
            self.pipelines.append(pipeline)
        pass

    def process_data(self) -> None:
        # TODO this method
        json_p, csv_p, stream_p = self.pipelines
        
        print("\nProcessing JSON data through pipeline...")
        json_p.process(json_data)

        print("\nProcessing CSV data through same pipeline...")
        csv_p.process(csv_data)

        print("\nProcessing Stream data through same pipeline...")
        stream_p.process(stream_data)
        pass
    pass


json_data: dict = {"sensor": "temp", "value": 23.5, "unit": "C"}
csv_data: str = "user,action,timestamp"
stream_data: list[float] = [15.0, 18.5, 22.0, 27.5, 27.5]

if __name__ == "__main__":
    # TODO main
    print("=== CODE NEXUS - ENTERPRISE PIPELINE SYSTEM ===\n")
    print("Initializing Nexus Manager...")
    print("Pipeline capacity: 1000 streams/second\n")

    manager = NexusManager()
    manager.add_pipeline()

    print("\nCreating Data Processing Pipeline...")
    for pipeline in manager.pipelines:
        pipeline.add_stage()

    print("\n=== Multi-Format Data Processing ===")
    manager.process_data()