import sys
n, m = map(int, sys.stdin.readline().split())
parent = [-1] * (n+1)
# print(*parent)


def my_find(u):
    if parent[u] < 0:
        return u
    my_p = my_find(parent[u])
    return my_p


def my_union(u, v):
    u = my_find(u)
    v = my_find(v)
    if u == v and u != -1 and v != -1:
        return False
    # global parent
    if parent[u] <= parent[v]:  # u가 더 크다면 -> u를 v에 붙여야한다
        parent[v] = u
        parent[u] -= 1
        # print(*parent)
    else:
        parent[u] = v
        parent[v] -= 1
        # print(*parent)

    return True


while m:
    m -= 1
    op, a, b = map(int, sys.stdin.readline().split())
    if a == b and op == 1:
        print("yes")
        continue

    if op == 0:
        my_union(a, b)
    else:
        if my_find(a) == my_find(b):
            print("YES")
        else:
            print("NO")
