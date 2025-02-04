import sys
from bisect import bisect_left

N = int(input())
nums = list(map(int, sys.stdin.readline().split()))
nums.sort()
cnt = 0


def binary_search(nums, exclude_idx, target):
    left, right = 0, len(nums) - 1
    while left < right:
        if left == exclude_idx:
            left += 1
            continue
        if right == exclude_idx:
            right -= 1
            continue
        if nums[left] + nums[right] == target:
            return True
        elif nums[left] + nums[right] < target:
            left += 1
        else:
            right -= 1
    return False


for i in range(N):
    if binary_search(nums, i, nums[i]):
        cnt += 1

print(cnt)
