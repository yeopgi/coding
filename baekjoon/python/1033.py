# 아직 다 풀지 못함

from dataclasses import dataclass
N = int(input())


class vertex:
    val: int = 0
    edge = []


visited = []
_vertex = [vertex() for i in range(N)]
for vtx in _vertex:
    vtx.val = False


def gcd(a, b):
    while b != 0:
        r = a % b
        a = b
        b = r
    return a


def dfs(cur, val):
    visited[cur] = True
    _vertex[cur].val *= val

    for next in _vertex[cur].edge:
        if visited[i] == False:
            dfs(next, val)


for i in range(0, N):
    a, b, p, q = map(int, input().split())
    if _vertex[a] == False:
        _vertex[a].val = 1
    if _vertex[b] == False:
        _vertex[b].val = 1

    g = gcd(_vertex[a].val, _vertex[b].val)
    print("g is : ")
    print(g)
    a_mod, b_mod = (_vertex[b].val / g) * p, (_vertex[a].val / g) * q
    g = gcd(a_mod, b_mod)
    visited = [0 for i in range(N)]
    dfs(a, a_mod / g)
    dfs(b, b_mod / g)

    _vertex[a].edge.append(b)
    _vertex[b].edge.append(a)

for i in range(0, N):
    print(_vertex[i].val)
