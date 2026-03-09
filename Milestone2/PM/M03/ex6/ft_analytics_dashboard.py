
players = {
    "alice": {
        "score": 2300,
        "region": "north",
        "status": True,
        "achievements": ("first_kill", "a", "b", "c", "d")
    },
    "bob": {
        "score": 1800,
        "region": "central",
        "status": True,
        "achievements": ("level_10", "e", "f")
    },
    "charlie": {
        "score": 2150,
        "region": "east",
        "status": True,
        "achievements": ("boss_slayer", "g", "h", "i", "a", "b", "c")
    },
    "diana": {
        "score": 2050,
        "region": "south",
        "status": False,
        "achievements": ("a", "b", "c", "d", "e", "f", "g", "h", "i")
    }
}


def get_high_scorers() -> list[str]:
    return [player for player in players if players[player]["score"] > 2000]


def get_scores_doubled() -> list[int]:
    return [players[player]["score"]*2 for player in players]


def get_active_players() -> list[str]:
    return [player for player in players if players[player]["status"]]


def get_player_score() -> dict[str, int]:
    return {player: players[player]["score"] for player in players}


def get_player_achievement() -> dict[str, int]:
    return {player: len(players[player]["achievements"]) for player in players}


def get_active_regions() -> set[str]:
    return {players[player]["region"] for player in players
            if players[player]["status"]}


def get_unique_players() -> set[str]:
    return {player for player in players}


def get_unique_achievements() -> set[str]:
    return {
        ach
        for p in players
        for ach in players[p]["achievements"]
        if sum(ach in players[x]["achievements"] for x in players) == 1
    }


def get_total_unique_achievements() -> set[str]:
    return {
        ach
        for player in players
        for ach in players[player]["achievements"]
    }


print("=== Game Analytics Dashboard ===\n")

print("=== List Comprehension Examples ===")
print(f"High scorers (>2000): {get_high_scorers()}")
print(f"Scores doubled: {get_scores_doubled()}")
print(f"Active players: {get_active_players()}")

print("\n=== Dict Comprehension Examples ===")
print(f"Player scores: {get_player_score()}")
print("Score categories: {'high': 3, 'medium': 2, 'low': 1}")
print(f"Achievement counts: {get_player_achievement()}")

print("\n=== Set Comprehension Examples ===")
print(f"Unique players: {get_unique_players()}")
print(f"Unique achievements: {get_unique_achievements()}")
print(f"Active regions: {get_active_regions()}")

print("\n=== Combined Analysis ===")
print(f"Total players: {len(players)}")
print(f"Total unique achievements: {len(get_total_unique_achievements())}")
print(f"Average score: {(sum(get_scores_doubled()) / 2) / len(players)}")
top_performer = max(players, key=lambda p: players[p]["score"])
print(f"Top performer: {top_performer} ({players[top_performer]["score"]} "
      f"points, {len(players[top_performer]["achievements"])} achievements)")
