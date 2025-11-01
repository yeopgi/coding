import sys

N = int(sys.stdin.readline().strip())
nums = [0] * (N + 1)

for i in range(1, N + 1):
    nums[i] = int(sys.stdin.readline().strip())
tot=0
for i in range(N, 0, -1):
    if i ==1:
        print(tot)
        break
    for j in range(i - 1, 0, -1):
        if (nums[j] >= nums[i]):
            minus_cnt = nums[j] - nums[i] + 1
            print(f"min : {minus_cnt}")
            tot += minus_cnt
            nums[j] = nums[i] - minus_cnt

# print(tot)
