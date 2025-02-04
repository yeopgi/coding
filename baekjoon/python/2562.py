import sys

n = int(input())
nums = list(map(int, sys.stdin.readline().split()))
max_num = -1000000 - 1
min_num = 1000000 + 1

for i in range(len(nums)):
    if max_num < nums[i]:
        max_num = nums[i]

    if min_num > nums[i]:
        min_num = nums[i]


print(min_num, end=' ')
print(max_num)
    