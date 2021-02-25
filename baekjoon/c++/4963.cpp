#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int w, h;
int map[51][51];
bool visit[51][51];
int cnt;
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

void Run(int x, int y)
{
    if (visit[x][y]) {
        return;
    }

    cnt++;
    visit[x][y] = true;
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && nx <= h && ny >= 1 && ny <= w) {
                if (!visit[nx][ny]) {
                    if (map[nx][ny] == 1) {
                        visit[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    while (1)
    {
        cin >> w >> h;
        if (w == 0 && h == 0) {
            break;
        }

        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> map[i][j];
            }
        }

        if (w == 1 && h == 1) {
            if (map[1][1] == 1) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }

            continue;
        }

        cnt = 0;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (map[i][j] == 1) {
                    Run(i, j);
                }
            }
        }

        cout << cnt << '\n';
        memset(visit, false, sizeof(visit));
    }

    return 0;
}