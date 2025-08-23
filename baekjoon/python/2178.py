import sys
from collections import deque
n,m = map(int, sys.stdin.readline().split())
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def Run():
    # map_str = sys.stdin.readline()
    maps = [[0] * m for _ in range(n)]
    for i in range(n):
        map_str = sys.stdin.readline()
        # print()
        for j in range(m):
            maps[i][j] = int(map_str[j])
            # print(maps[i][j], end ='')

        # print()
        
    visited = [[0] * m for _ in range(n)]
    # print(*visited)
    my_q = deque()
    my_q.append((0, 0, 0))
    cnt = 0
    while (my_q):
        # print(1)
        curr_coord = my_q.popleft()
        cx = curr_coord[0]
        cy = curr_coord[1]
        visited[cx][cy] =1 
        cnt = curr_coord[2] + 1
        if (cx == n - 1 and cy == m - 1):
            # print('abc')
            return cnt
        
        # print(*maps)
        for k in range(0, 4):

            nx = cx + dx[k]
            ny = cy + dy[k]
            if (nx >= 0 and nx < n and ny >= 0 and ny < m):
                if visited[nx][ny] == 0 and maps[nx][ny] == 1:
                    my_q.append((nx, ny, cnt))
                    visited[nx][ny] =1 

    # print(cnt)
    # for i in range(0, n):
    #     for j in range(0, m):
    #         if (visited[i][j]):
    #             continue

    #         if (maps[i][j] == 1):

print(Run())        
