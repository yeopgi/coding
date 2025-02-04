import sys

n, s = map(int, sys.stdin.readline().split())
temp_nums = list(map(int, sys.stdin.readline().split()))
# print(*temp_nums)
nums = [0] * (n + 1)
for i in range(len(temp_nums)):
    nums[i+1] = temp_nums[i]

# print(*nums)
cnt = 0
def Run(idx, total_sum):
    global cnt
    if (idx == n):
        if(total_sum == s):
            cnt += 1
        return

    Run(idx+1, total_sum)
    Run(idx+1, total_sum + temp_nums[idx])

Run(0, 0)
if s == 0:
    cnt -=1
# print('cnt -> ', end='')
print(cnt)
    

