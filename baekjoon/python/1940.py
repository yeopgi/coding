import sys

N = int(input())
M = int(input())
nums = list(map(int, input().split()))
# if (N == 1 or M == 1):
#     print(0)
#     sys.exit()
cnt = 0
nums.sort()
i = 0
j = N-1
while (i < j):
    if (nums[i] + nums[j] == M):
        cnt += 1
        i += 1
    elif (nums[i] + nums[j] < M):
        i += 1
    else:
        j -= 1
print(cnt)
