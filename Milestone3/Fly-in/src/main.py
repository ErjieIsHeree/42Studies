
from infrastructure.parsers.text_parser import TxtParser
from infrastructure.application.domain import Simulator

file = "../.maps/easy/01_linear_path.txt"

parser = TxtParser()
s: Simulator = parser.get_simulator(file)
a = [hub.name for hub in s.hubs]
print(a)
