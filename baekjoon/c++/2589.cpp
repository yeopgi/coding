#include <queue>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int a[50][50];
int result[50][50];
int row, col;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visit[50][50];

int Run(int start, int end)
{
    queue<pair<int, int>> q;
    q.push({start, end});
    visit[start][end] = true;
    int maxNum = 0;;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if (nextX >= 0 && nextX < row && nextY >= 0 && nextY < col) {
                if (!visit[nextX][nextY]) {
                    if (a[nextX][nextY] == 'L') {
                        visit[nextX][nextY] = true;
                        result[nextX][nextY] = result[x][y] + 1;
                        maxNum = max(result[nextX][nextY], maxNum);
                        q.push({nextX, nextY});
                    }
                }
            }
        }
    }

    return maxNum;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> row >> col;
    vector<pair<int, int>> land;
    for (int i = 0; i < row; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            a[i][j] = str[j];
            if (str[j] == 'L') {
                land.push_back({i, j});
            }
        }
    }

    int maxNum = 0;
    for (int i = 0; i < land.size(); i++) {
        maxNum = max(Run(land[i].first, land[i].second), maxNum);
        memset(visit, false, sizeof(visit));
        memset(result, 0, sizeof(result));
    }

    cout << maxNum << '\n';
    return 0;
}