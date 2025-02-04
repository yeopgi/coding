import sys

N, M = map(int, sys.stdin.readline().split())
nums = list(map(int, sys.stdin.readline().split()))
# print(*nums)
for i in range(1, N):
    nums[i] += nums[i - 1]
# print(*nums)
cnt = 0
mods = [0] * M
for i in range(0, N):
    nums[i] %= M
    # print(nums[i])
    if (nums[i] == 0):
        cnt += 1
        # print("fsdf")
    mods[nums[i]] += 1
# print(*nums)
# print(*mods)
for i in range(M):
    if (mods[i] > 1):
        cnt += (mods[i] * (mods[i] -1) // 2)
        # print(cnt)
print(cnt)

    



