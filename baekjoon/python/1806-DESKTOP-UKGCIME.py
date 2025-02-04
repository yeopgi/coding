import sys
n, s = map(int, sys.stdin.readline().split())
if s == 1:
    print(1)
    exit()
arr = list(map(int, sys.stdin.readline().split()))
min_len = 987654321
left =0
right=0
sum=0
while (right < n and left<=right):
    if sum > s:
        sum -= arr[left]
        left +=1
        # min_len = min(min_len, right - left +1)

        # print(f"sum1 : {sum}")

    elif sum == s:
        min_len = min(min_len, right - left +1)
        print(f"right : {right}, left : {left}, min_len : {min_len}")
        right +=1
        left = right
        sum=0

    else:
        # print("hello3")

        sum += arr[right]
        right += 1

print(min_len)
            