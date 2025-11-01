import sys
v, e = map(int, sys.stdin.readline().split())
parent = [-1] * (v+1)
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

inputs = []

for _ in range(e):
    inputs.append(list(map(int, sys.stdin.readline().split())))

inputs.sort(key=lambda x: x[2])

edge_cnt =0
edge_val=0
for _ in range(e):
    a, b, val = inputs[_]
    if (my_union(a, b)):
        edge_val += val
        edge_cnt += 1
        if (edge_cnt == v - 1):
            break

print(edge_val)
# print(*inputs)