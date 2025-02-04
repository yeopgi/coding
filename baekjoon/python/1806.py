import sys
n, s = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))
min_len = 987654321
left =0
right=0
sum=arr[0]
while (right < n and left<=right):
    if sum >= s:
        # print(f"right : {right}, left : {left}, min_len : {min_len}")
        min_len = min(min_len, right - left +1)
        sum -= arr[left]
        left +=1
        # print(f"sum1 : {sum}")
    else:
        # print("hello3")
        if (right == n-1):
            break
        right += 1



        
        sum += arr[right]

if (min_len == 987654321):
    min_len = 0

print(min_len)
            