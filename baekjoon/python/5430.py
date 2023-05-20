from audioop import reverse
import sys
from collections import deque

t = int(input())

for i in range(t):
    reverse_cnt = 0
    p = sys.stdin.readline().rstrip()
    n = int(input())
    arr = deque(sys.stdin.readline().rstrip()[1:-1].split(","))
    j = True
    for i in range(0, len(p)):
        if p[i] == 'R':
            reverse_cnt += 1

        elif p[i] == 'D':
            if n == 0 or len(arr) == 0:
                print("error")
                j = False
                break

            if reverse_cnt % 2 == 0:
                arr.popleft()
                continue

            arr.pop()

    if (j == False):
        continue

    if reverse_cnt % 2 == 0:
            print("[" + ",".join(arr) + "]")
    else:
        arr.reverse()
        print("[" + ",".join(arr) + "]")
