col = 6
square_cnt = int(input())
arr = [[0 for j in range(1, col + 1)] for i in range(1, square_cnt + 1)]

for i in range(1, square_cnt + 1) :
    for j in range(1, col + 1):
        arr[i][j] = int(input())

pair_list = 