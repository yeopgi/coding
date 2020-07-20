#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
bool visit[101][101];
int N;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;

void floydWashall() {
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (map[i][j] > map[i][k] + map[k][j]) {
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }
}

void Bfs(pair<int, int> src) 
{
    int x = src.first, y = src.second;
    if (visit[x][y]) {
        return;
    }

    visit[x][y] = true;
    q.push({x, y});

    while (!q.empty()) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (!visit[nx][ny] && nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                if (map[nx][ny] == 1) {
                    map[ny][nx] = 1;
                    q.push({nx, ny});
                }
            }
        }

        q.pop();
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }

    floydWashall();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << map[i][j] << ' ';
        }

        cout << '\n';
    }

    return 0;
}