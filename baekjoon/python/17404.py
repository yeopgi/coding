import sys

N = int(sys.stdin.readline())
cost = []
for _ in range(N):
    cost.append(list(map(int, sys.stdin.readline().split())))

ans = float('inf')

for first_color in range(3):
    dp = [[0] * 3 for _ in range(N)]

    for i in range(3):
        if i == first_color:
            dp[0][i] = cost[0][i]
        else:
            dp[0][i] = float('inf')

    for i in range(1, N):
        dp[i][0] = cost[i][0] + min(dp[i-1][1], dp[i-1][2])
        dp[i][1] = cost[i][1] + min(dp[i-1][0], dp[i-1][2])
        dp[i][2] = cost[i][2] + min(dp[i-1][0], dp[i-1][1])

    for last_color in range(3):
        if first_color != last_color:
            ans = min(ans, dp[N-1][last_color])

print(ans)