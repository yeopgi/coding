#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
const int INF = 987654321;
int N, M;
int map[101][101];
int runningMap[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void Bfs(pair<int, int> point) {
    int x = point.first, y = point.second;
    runningMap[1][1] = 0;
    q.push({x, y});

    while (!q.empty()) {
        x = q.front().first, y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
                if (map[nx][ny] == 1) {
                    if (runningMap[nx][ny] > runningMap[x][y] + 1) {
                        runningMap[nx][ny] = runningMap[x][y] + 1;
                        q.push({nx, ny});
                    }
                } else if (map[nx][ny] == 0) {
                    if (runningMap[nx][ny] > runningMap[x][y]) {
                        runningMap[nx][ny] = runningMap[x][y];
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;
    for (int i = 1; i <= N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            map[i][j + 1] = str[j] - '0';
            runningMap[i][j + 1] = INF;
        }
    }

    Bfs({1, 1});

    cout << runningMap[N][M] << '\n';
    return 0;
}