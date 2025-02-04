import sys

n, r,c = map(int, sys.stdin.readline().split())
tot_cnt = 0
def Run(n, x_pos, y_pos):
    global tot_cnt
    if (n==0):
        return 0

    half = 1 << (n-1)
    if (x_pos < half and y_pos < half):
        return Run(n-1, x_pos, y_pos)

    if (x_pos < half and y_pos >= half):
        return half * half + Run(n-1, x_pos, y_pos - half)

    if (x_pos >= half and y_pos < half):
        return 2 * (half * half) + Run(n-1, x_pos - half, y_pos)

    if (x_pos >= half and y_pos >= half):
        return 3 * (half * half) + Run(n-1, x_pos - half, y_pos - half)


print(Run(n, r, c))