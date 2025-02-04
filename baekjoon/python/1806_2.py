import sys
n, s = map(int, sys.stdin.readline().split())
if s == 1:
    print(1)
    exit()
arr = list(map(int, sys.stdin.readline().split()))
min_len = 987654321
left =0, right=0, sum=0
while (right < n and left<n):
    if sum > s:
        left +=1
    elif sum == s:
        min_len = min(min_len, right - left +1)
        right +=1
        left = right
        sum=0

    else:
        sum += arr[right]
        right += 1

print(min_len)
            