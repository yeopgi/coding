import sys
input = sys.stdin.read
data = input().split()

index = 0
len = int(data[index])
index += 1
case_cnt = int(data[index])
index += 1

numbers = [0] * (len + 1)
dp = [0] * (len + 1)
for i in range(1, len + 1):
    temp = int(data[index])
    index += 1
    numbers[i] = temp
    dp[i] = dp[i - 1] + numbers[i]
results = []
for i in range(case_cnt):
    start = int(data[index])
    index += 1
    end = int(data[index])
    index += 1
    results.append(dp[end] - dp[start - 1])
for result in results:
    print(result)