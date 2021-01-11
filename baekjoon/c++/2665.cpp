#include <iostream>
#include <cstring>      // memset
#include <queue>
#include <string>
using namespace std;

priority_queue<pair<int, pair<int, int>>> pq;   // <갯수, 좌표<int, int>>
string map[51];
bool visit[51][51][51 * 51];
int result[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n;

int Bfs(int x, int y)
{
    pq.push({0, {x, y}});
    while (!pq.empty()) {
        if (pq.top().second.first == n -1 && pq.top().second.second == n - 1) {
            cout << "asdas" << endl;
            return -(pq.top().first);
        }

        for (int i = 0; i < 4; i++) {
            int temp = -(pq.top().first);
            x = pq.top().second.first + dx[i];
            y = pq.top().second.second + dy[i];
            //cout << "in " << x << " " << y << ' ' << temp << endl;
            //if (x == 8 && y == 8)
            //    return 9;
            if (x >= 0 && x <= n -1 && y >= 0 && y <= n - 1) {
                if (map[x][y] == '0') {
                    temp++;
                }

                if (visit[x][y][temp]) {
                    continue;
                }

                visit[x][y][temp] = true;
                pq.push({-temp, {x, y}});
            }
        }

        pq.pop();
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }

    visit[0][0][0] = true;
    cout << "hello" << '\n';
    cout << Bfs(0, 0) << '\n';
    return 0;
}