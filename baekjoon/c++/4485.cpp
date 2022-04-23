#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

priority_queue<pair<int, pair<int, int>>> pq;
const int INF = 987654321;
int map[126][126];
int ret[126][126];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int input;

int Bfs(int x, int y)
{
    pq.push({-map[x][y], {x, y}});
    ret[x][y] = map[x][y];
    while (!pq.empty()) {
        int cost = 0;
        x = pq.top().second.first;
        y = pq.top().second.second;
        cost = (-pq.top().first);
        pq.pop();
        if (cost > ret[x][y]) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && nx <= input && ny >= 1 && ny <= input) {
                int temp = cost + map[nx][ny];
                if (ret[nx][ny] > temp) {
                    ret[nx][ny] = temp;
                    pq.push({-temp, {nx, ny}});
                }
            }
        }
    }

    return ret[input][input];
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt = 1;
    while (true) {
        cin >> input;
        if (input == 0) {
            break;
        }

        for (int i = 1; i <= input; i++) {
            for (int j = 1; j <= input; j++) {
                cin >> map[i][j];
            }
        }

        fill(&ret[0][0], &ret[0][0] + (sizeof(ret) / 4), INF);

        cout << "Problem" << ' ' << cnt++ << ": " << Bfs(1, 1) << '\n';
    }

    return 0;
}