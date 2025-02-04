N = int(input())
sum = 1
right =1
left =1
# numbers = [i for i in range(1, N+1)]
tot = 0
while (right <= N and left <= right):
    if (sum > N):
        sum -= left
        # sum -= numbers[left]
        left += 1
    elif (sum == N):
        tot += 1
        sum -= left
        left += 1
    else:
        right += 1
        # print(right)
        sum += right

print(tot)