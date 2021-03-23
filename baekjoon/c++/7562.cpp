#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int nowX, nowY, dstX, dstY, l;
bool visit[300][300];
int map[300][300];
int dx[8] = {1, 2, -2, -1, -1, -2, 2, 1};
int dy[8] = {-2, -1, -1, -2, 2, 1, 1, 2};

void init()
{
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            map[i][j] = 0;
        }
    }
}

int Bfs(int x, int y) {
    //init();

    queue<pair<int, int>> q; // 목적지 도착시에 남아있는 큐의 원소들을 모두 제거하기 위해 Bfs안에서 큐 생성
    q.push({x, y});
    while (!q.empty()) {
        int xTemp = q.front().first;
        int yTemp = q.front().second;
        q.pop();

        if (xTemp == dstX && yTemp == dstY) {
            return map[xTemp][yTemp];
        }

        for (int i = 0; i < 8; i++) {
            x = xTemp + dx[i], y = yTemp + dy[i];
            if (x >= 0 && x < l && y >= 0 && y < l) {
                if (!visit[x][y]) {
                    visit[x][y] = true;
                    if (map[x][y] < map[xTemp][yTemp] + 1) {
                        map[x][y] = map[xTemp][yTemp] + 1;
                    }

                    q.push({x, y});
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCase;
    cin >> testCase;
    while (testCase--) {
        memset(visit, false, sizeof(visit));
        memset(map, 0, sizeof(map));
        cin >> l;
        cin >> nowX >> nowY;
        cin >> dstX >> dstY;
        if (nowX == dstX && nowY == dstY) {
            cout << 0 << '\n';
            continue;
        }

        cout << Bfs(nowX, nowY) << '\n';
    }

    return 0;
}