import sys

dp = [0 for _ in range(0, 1000001)]
before = [0 for _ in range(0, 1000001)]

N = int(input())

def solve():
    dp[1] = 0
    before[1] = -1
    for i in range(2, N + 1):
        dp[i] = dp[i - 1] + 1
        before[i] = i - 1
        if 0 == (i % 2) and (dp[int(i / 2)] + 1) < dp[i]:
            dp[i] = dp[int(i / 2)] + 1
            before[i] = int(i / 2)

        if (0 == i % 3) and (dp[int(i / 3)] + 1) < dp[i]:
            dp[i] = dp[int(i / 3)] + 1
            before[i] = int(i / 3)

solve()
print(dp[N])

idx = N
while -1 != idx:
    print(idx, end = ' ')
    idx = before[idx]
