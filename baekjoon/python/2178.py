import sys
from collections import deque
n,m = map(int, sys.stdin.readline().split())
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def Run():
    # map_str = sys.stdin.readline()
    # maps = [sys.stdin.readline() for _ in range(n)]
    for _ in range(n):
        map_str = sys.stdin.readline()
        print()
        for i in range(m):
            print(map_str[i], end ='')

        print()
        
    # maps = [list(map(int, input().split())) for _ in range(n)]
    # visited = [[0] * m for _ in range(n)]
    # my_q = deque()
    # # print(*maps)
    # for i in range(0, n):
    #     for j in range(0, m):
    #         if (visited[i][j]):
    #             continue

    #         if (maps[i][j] == 1):
    #             my_q.append((i, j))
    #             cnt = 0
    #             while (my_q):
    #                 # print(1)
    #                 curr_coord = my_q.popleft()
    #                 cx = curr_coord[0]
    #                 cy = curr_coord[1]
    #                 visited[cx][cy] =1 
    #                 cnt = cnt + 1
    #                 if (cx == n and cy ==m):
    #                     return cnt

    #                 for k in range(0, 4):
    #                     nextX = cx + dx[k]
    #                     nextY = cy + dy[k]
    #                     if (nextX >= 0 and nextX < n and nextY >= 0 and nextY < m):
    #                         if visited[nextX][nextY] == 0 and maps[nextX][nextY] == 1:
    #                             my_q.append((nextX, nextY))
    #                             visited[nextX][nextY] =1 

Run()
# print(Run())        
