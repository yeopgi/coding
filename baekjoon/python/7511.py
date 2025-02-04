import sys
t_num = int(input())
u_num = int(input())

f_num = int(input())

f_group = [-1] * (f_num )
print(*f_group)

def find_root(curr_num):
    if f_group[curr_num] == -1:
        return curr_num
    
    root_num = find_root(curr_num)
    return root_num
def union(num1, num2):
    root1 = find_root(num1)
    root2 = find_root(num2)

    if root1 == root2:
        return False

    f_group[num2] = root1
    return True

for _ in range(t_num):
    for _ in range(f_num):
        a,b= map(int ,sys.stdin.readline().split())
        if union(a,b):
            print(1)
        else:
            print(0)