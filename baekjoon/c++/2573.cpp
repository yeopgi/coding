#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int map[301][301];
int meltingMap[301][301];
bool visit[301][301];
vector<pair<size_t, size_t>> ice;
queue<pair<size_t, size_t>> q;
int row, col;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void Melting(pair<size_t, size_t> start) 
{
    if (map[start.first][start.second] <= 0) {
        return;
    }

    for (size_t i = 0; i < 4; i++) {
        int xTemp = start.first + dx[i];
        int yTemp = start.second + dy[i];
        if (xTemp >= 1 && yTemp >= 1 && xTemp <= row && yTemp <= col) {
            if (map[xTemp][yTemp] <= 0) {
                meltingMap[start.first][start.second]++;
            }
        }
    }
}

void Explore(pair<size_t, size_t> start)
{
    visit[start.first][start.second] = true;
    q.push({start.first, start.second});
    while (!q.empty()) {
        for (size_t i = 0; i < 4; i++) {
            int xTemp = q.front().first + dx[i];
            int yTemp = q.front().second + dy[i];
            if (xTemp >= 1 && yTemp >= 1 && xTemp <= row && yTemp <= col && map[xTemp][yTemp] > 0 && !visit[xTemp][yTemp]) {
                q.push({xTemp, yTemp});
                visit[xTemp][yTemp] = true;
            }
        }

        q.pop();
    }
}

int main(void) 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> row >> col;
    for (size_t i = 1; i <= row; i++) {
        for (size_t j = 1; j <= col; j++) {
            cin >> map[i][j];
        }
    }

    for (size_t k = 1;; k++) {
        for (size_t i = 1; i <= row; i++) {
            for (size_t j = 1; j <= col; j++) {
                Melting({i, j});
                map[i][j] = map[i][j] - meltingMap[i][j];
                if (map[i][j] > 0) {
                    ice.push_back({i, j});
                }
            }
        }

        Explore(ice[0]);
        
        for (size_t i = 0; i < ice.size(); i++) {
            if (!visit[ice[i].first][ice[i].second]) {
                cout << k << '\n';
                return 0;
            }
        }

        ice.clear();
        
        memset(meltingMap, 0, sizeof(meltingMap));
        memset(visit, false, sizeof(visit));
    }

    return 0;
}