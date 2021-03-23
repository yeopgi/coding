#include <iostream>
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
        int temp = -(pq.top().first);
        x = pq.top().second.first;
        y = pq.top().second.second;
        pq.pop();
        if (x == n - 1 && y == n - 1) {
            return temp;
        }

        for (int i = 0; i < 4; i++) {
            int cnt = temp;
            int xTemp = x + dx[i];
            int yTemp = y + dy[i];
            if (xTemp >= 0 && xTemp <= n - 1 && yTemp >= 0 && yTemp <= n - 1) {
                if (map[xTemp][yTemp] == '0') {
                    cnt++;
                }

                if (visit[xTemp][yTemp][cnt]) {
                    continue;
                }

                visit[xTemp][yTemp][cnt] = true;
                pq.push({-cnt, {xTemp, yTemp}});
            }
        }
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
    cout << Bfs(0, 0) << '\n';
    return 0;
}