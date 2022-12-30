#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

void BFS(int x, int y);

int map[101][101] = {
    0,
};
int check[101][101] = {
    0,
};
int dx[] = {-1, 0, 1, 0}; 
int dy[] = {0, 1, 0, -1};
int n, m;

int main() 
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
        }
    } 

    BFS(0, 0);

    printf("%d\n", check[n - 1][m - 1]); 
}

void BFS(int x, int y) 
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    check[x][y] = 1;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) { 
            int xTemp = x + dx[i];
            int yTemp = y + dy[i];
            if (0 <= xTemp && xTemp < n && 0 <= yTemp && yTemp < m) {
                if (check[xTemp][yTemp] == 0 && map[xTemp][yTemp] == 1) {
                    q.push(make_pair(xTemp, yTemp));
                    check[xTemp][yTemp] = check[x][y] + 1;
                }
            }
        }
    }
}