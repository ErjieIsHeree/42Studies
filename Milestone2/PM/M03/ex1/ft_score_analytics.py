
import sys

argv: list[str] = sys.argv
nargv: list[int] = []
argc: int = len(argv)
nargc: int = 0
i: int = 1
arg: int = 0
total_points: int = 0

if argc != 1:
    try:
        while i < argc:
            nargv.append(int(argv[i]))
            i += 1
        nargc = len(nargv)
        print("=== Player Score Analytics ===")
        print(f"Scores processed: {nargv}")
        print(f"Total players: {nargc}")
        print(f"Total score: {sum(nargv)}")
        print(f"Average score: {sum(nargv) / nargc}")
        print(f"High score: {max(nargv)}")
        print(f"Low score: {min(nargv)}")
        print(f"Score range: {max(nargv) - min(nargv)}\n")
    except ValueError:
        print(f"Im gonna '{argv[i]}' you")
else:
    print("=== Player Score Analytics ===")
    print("No scores provided. Usage: python3 ft_score_analytics.py <score1> "
          "<score2> ...")
