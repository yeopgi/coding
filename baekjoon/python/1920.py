import sys

N = int(input())
my_arr_element = list(map(int, input().split()))

my_arr_element.sort()

flag_list =[]

def do_searching(start_idx, end_idx, searching_num):
    if (start_idx > end_idx):
        return

    mid = int((start_idx + end_idx) / 2)
    if my_arr_element[mid] == searching_num:
        flag_list.append(1)
        return

    if (my_arr_element[mid] > searching_num):
        end_idx = mid - 1
        do_searching(start_idx, end_idx, searching_num)
    else:
        start_idx = mid + 1
        do_searching(start_idx, end_idx, searching_num)

    return


M = int(input())
target_element = list(map(int, input().split()))
for i in range(0, M):
    flag_list.clear()
    do_searching(0,N  - 1, target_element[i])
    if (len(flag_list) == 0):
        print(0)
        continue

    print(1)


