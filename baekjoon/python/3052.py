nums= [0] * 10
my_list = [0] * 42
for i in range(10):
    nums[i] = int(input())
    nums[i] = nums[i] % 42
    my_list[nums[i]] += 1
cnt = 0
for i in range(42):
    if (my_list[i] > 0):
        cnt += 1

print(cnt)



