import sys
k,p,n = map(int, sys.stdin.readline().split())
nums = []
mod_num = 1000000007
def Run():
    nums.append(k % mod_num)
    for i in range(0, n):
        nums.append(p % mod_num)

    res = 1
    for i in range(0, len(nums)):
        res = res* nums[i]

    return res % mod_num

print(Run())