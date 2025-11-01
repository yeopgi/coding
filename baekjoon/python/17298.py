import sys
from collections import deque
mydeque = deque()
N = int(sys.stdin.readline())
ans = [-1] * (N+1)
nums = [(-1, -1)] * (N+1)
nums_bak = list(map(int, sys.stdin.readline().split()))
for i in range(1, N+1):
    nums[i] = (i, nums_bak[i-1])  # (index, value)

# print(*nums[1:])
for i in range(1, N + 1):
    if len(mydeque) == 0:
        mydeque.append(nums[i])
    else:
        while len(mydeque) > 0:
            if mydeque[-1][1] < nums[i][1]:
                ans[mydeque[-1][0]] = nums[i][1]
                mydeque.pop()
            else:
                break
        mydeque.append(nums[i])
print(*ans[1:])
