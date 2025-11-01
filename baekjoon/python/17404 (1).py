import sys

def solve():
    n_str = sys.stdin.readline()
    if not n_str:
        return
    n = int(n_str)
    
    costs = []
    for _ in range(n):
        line = sys.stdin.readline()
        if not line:
            break
        costs.append(list(map(int, line.split())))
    if not costs:
        return
    dp = [[0] * 3 for _ in range(n)]
    dp[0][0] = costs[0][0]
    dp[0][1] = costs[0][1]
    dp[0][2] = costs[0][2]
    prev_color = 0
    for i in range(1, n):
        if (prev_color == 0):
            dp[i][1] = costs[i][1] + dp[i-1][prev_color]
            dp[i][2] = costs[i][2] + dp[i-1][prev_color]
            if dp[i][1] < dp[i][2]:
                prev_color = 1
                
            else:
                prev_color = 2
    



    print(min(dp[n-1]))

solve()