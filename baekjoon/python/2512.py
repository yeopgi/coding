import sys
input = sys.stdin.readline
N = int(input())
member = list(map(int, input().split()))
total_money = int(input())
start = 0
end = max(member)

mid = 0
mid_val = 0

while (start <= end):
    mid = int((start + end) / 2)
    sum = 0
    for i in range(0, len(member)):
        sum += min(member[i], mid)

    if (sum > total_money):
        end = mid - 1
    else:
        start = mid + 1
        mid_val = max(mid_val, mid)
        #print(mid_val)

print(mid_val)

