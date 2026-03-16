from abc import ABC, abstractmethod


class DataStream(ABC):
    @abstractmethod
    def process_batch(self, data_batch: List[Any]) -> str: ...
    
    @abstractmethod
    def filter_data(self, data_batch: List[Any], criteria: Optional[str] = None) -> List[Any]: ...
    
    @abstractmethod
    def get_stats(self) -> Dict[str, Union[str, int, float]]: ...
    pass



