import sys

nums = list(map(int, sys.stdin.readline().split()))
res = "descending"
if nums[0] == 1:
    max_num = nums[0]
    for i in range(1, len(nums)):
        if (max_num < nums[i]):
            max_num = nums[i]
        else:
            res = "mixed"
            print(res)
            exit()

    print("ascending")
elif nums[0] ==8:
    min_num = nums[0]
    for i in range(1, len(nums)):
        if (min_num > nums[i]):
            min_num = nums[i]
        else:
            res = "mixed"
            print(res)
            exit()

    print("descending")
else:
    print("mixed")


