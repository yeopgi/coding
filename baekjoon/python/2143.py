import sys
from collections import defaultdict
T = int(sys.stdin.readline())
n = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))
m = int(sys.stdin.readline())
B = list(map(int, sys.stdin.readline().split()))
partial_a = []
partial_b = []
for i in range(n):
    partial_a.append(A[i])
for i in range(1, n):
    A[i] += A[i-1]
for i in range(1,n):
    partial_a.append(A[i])

for i in range(m):
    partial_b.append(B[i])
for i in range(1, m):
    B[i] += B[i-1]
for i in range(1, m):
    partial_b.append(B[i])

for i in range(1, n):
    for j in range(i + 1, n):
        partial_a.append(A[j] - A[i-1])

for i in range(1, m):
    for j in range(i + 1, m):
        partial_b.append(B[j] - B[i-1])

countA = defaultdict(int)
for num in partial_a:
    countA[num] += 1

countB = defaultdict(int)
tot = 0
for num in partial_b:
    tot += countA[T-num]

print(tot)

