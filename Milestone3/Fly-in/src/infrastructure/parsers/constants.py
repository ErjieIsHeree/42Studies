EMPTY_FILE_ERROR = "[ERROR]: This file is empty"
FIRST_LINE_ERROR = (
    "[ERROR] at line {i}: First line must follow this ""syntax 'nb_drones: <nu"
    "mber>'"
)
NEGATIVE_NB_DRONES_ERROR = (
    "[ERROR] at line {line_nb}: max_drones value must be positive.")
FILE_CONSTRAINTS_ERROR = (
    "Error at line {i}: The line must be empty, a comment (a line which starts"
    " with a '#') or a hub/connection. You can find the constraints of them be"
    "low:\n\nHub.\nhub: <name> <x_coordinate> <y_coordinate> [zone=<normal|blo"
    "cked|restricted|priority> color=<string> max_drones=<positive_number>]\nF"
    "or starter and end hubs there is only one difference between, they start "
    "with either start_hub or end_hub correspondingly.\n\nConnection.\nconnect"
    "ion: <hub1>-<hub2> [max_link_capacity=<positive_number>]\nThe hubs must b"
    "e created previously.\n\nTake in mind that the data between the clasps ar"
    "e optional, but must follow the same syntaxis. If any is choosen."
)
REPEATED_HUB_ID_ERROR = (
    "[ERROR] at line {line_nb}: This hub name is already in use.")
NEGATIVE_MAX_LINK_CAPACITY_ERROR = (
    "[ERROR] at line {line_nb}: max_link_capacity value must be positive."
)
UNEXISTING_CONN_ERROR = (
    "[ERROR] at line {line_nb}: A hub or both of the connection doesn't exist."
)
REPEATED_CONN_ERROR = (
    "[ERROR] at line {line_nb}: The connection is repeated."
)


NB_DRONES_REGEX = r"^nb_drones:\s+\d+\s*\n$"
SEARCH_NB_DRONES_REGEX = r"^nb_drones:\s+(?P<nb_drones>\d+)\s*\n?$"
HUBS_REGEX = (
    r"^(?:start_|end_)?hub:\s+[^\s\-]+\s+\-?\d+\s+\-?\d+(?:\s+\[(?:zone=(?:nor"
    r"mal|blocked|restricted|priority)(?:\s+color=[a-zA-Z]+)?(?:\s+max_drones="
    r"\d+)?|color=[a-zA-Z]+(?:\s+max_drones=\d+)?|max_drones=\d+)\])?\s*\n?$"
)
SEARCH_HUB_DATA_REGEX = (
    r"^(start_|end_)?hub:\s+(?P<name>.*?)\s+(?P<x>.*?)\s+(?P<y>.*?)(?:\s+\[(?:"
    r"zone=(?P<zone>(?:normal|blocked|restricted|priority))\s*)?(?:color=(?P<c"
    r"olor>[a-zA-Z]+)\s*)?(?:max_drones=(?P<max_drones>\d+))?\])?\s*\n?$"
)
CONNECTION_REGEX = (
    r"^connection:\s+[^\s\-]+\-[^\s\-]+(\s+\[max_link_capacity=\d+\])?\s*\n?$"
)
SEARCH_CONNECTION_DATA_REGEX = (
    r"^.*?\s+(?P<hub1>.*?)\-(?P<hub2>.*?)(?:\s+\[max_link_capacity=(?P<max_lin"
    r"k_capacity>\d+)\])?\s*\n?$"
)
