import sys
t_num = int(input())


f_group = [-1] * (1000001)
# print(*f_group)

def find_root(curr_num):
    if f_group[curr_num] < 0:
        return curr_num
    
    root_num = find_root(f_group[curr_num])
    f_group[curr_num] = root_num
    return f_group[curr_num]

def union(num1, num2):
    num1 = find_root(num1)
    num2 = find_root(num2)

    if num1 == num2:
        return 0

    if f_group[num2] < f_group[num1]:
        temp = num1
        num1 = num2
        num2 = temp

    if f_group[num2] == f_group[num1]:
        f_group[num1] -= 1

    f_group[num2] = num1
    return 1

for t in range(t_num):
    for i in range(1000001):
        f_group[i] = -1
    u_num = int(input())
    f_num = int(input())
    for _ in range(f_num):
        a,b= map(int ,sys.stdin.readline().split())
        union(a,b)

    m = int(input())
    print(f"Scenario {t+1}:")
    for _ in range(m):
        u, v = map(int ,sys.stdin.readline().split())
        if find_root(u) == find_root(v):
            print(1)
        else:
            print(0)
        # print(find_root(u) == find_root(v))
    print()
