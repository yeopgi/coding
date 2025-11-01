import sys
N = int(sys.stdin.readline().strip())
M = int(sys.stdin.readline().strip())

maps = [list(map(int, input().split())) for _ in range(N)]
candidate = list(map(int, input().split()))
print(candidate)