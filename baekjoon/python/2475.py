import sys

nums = list(map(int, sys.stdin.readline().split()))
tot = (nums[0] * nums[0]) + (nums[1] * nums[1]) + (nums[2] * nums[2]) + (nums[3] * nums[3]) + (nums[4] * nums[4])
res= tot % 10

print(res)


