import sys

C, N = map(int, sys.stdin.readline().split())
nums = []
d  = [987654321] * (C + 100)
while N > 0:
    money, people = map(int, sys.stdin.readline().split())
    nums.append((money, people))
    N -= 1
d[0] = 0
for mon, peo in nums:
    for i in range(peo, C + 100):
        d[i] = min(d[i], d[i - peo] + mon)

print(min(d[C:])) 
    



# d[3] -> (d[3]는 3명의 사람을 모으는 최소 비용)
# d[3] = min(d[3] + 0, d[1] + 2, d[2] + 1) -> 인덱스와 상수를 합치면 사람 수가 된다.

