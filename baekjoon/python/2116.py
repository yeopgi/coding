list = [[0 for _ in range(1, 20)] for _ in range(1, 20)]
BLACK_CIRCLE = 1
WHITE_CIRCLE = 2
color_list = [BLACK_CIRCLE, WHITE_CIRCLE]
NONE_CIRCLE  = 0

board = []
for i in range(1, 20):
    for j in range(1, 20):
        board.append(list(map(int, input().split())))

dx = [-1, 1, 0, 0,-1, 1, -1, 1]
dy = [0, 0, -1, 1,-1, 1, 1, -1]

for k in range(0, len(color_list)):
    for i in range(1, 20):
        for j in range(1, 20):
            if board[i][j] is color_list[k]:
                