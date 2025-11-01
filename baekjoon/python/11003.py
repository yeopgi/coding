import sys
from collections import deque
N, L = map(int, sys.stdin.readline().split())
nums = list(map(int, sys.stdin.readline().split()))
# print(*nums)
mydeque = deque()
for i in range(N):
    while (mydeque and mydeque[-1][0] > nums[i]):
        mydeque.pop()

    mydeque.append((nums[i], i))
    if (mydeque[0][1] <= i - L):
        # print(mydeque[0][1], end=' ')
        mydeque.popleft()
    print(mydeque[0][0], end=' ')
