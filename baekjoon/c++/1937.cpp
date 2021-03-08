#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 500;
int a[MAX + 1][MAX + 1];
int copy[MAX + 1][MAX + 1];
int n;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int Run(int startX, int startY, int prev, bool visit[][501])
{
    if (a[startX][startY] < prev) {
        return 1;
    }

    visit[startX][startY] = true;
    int maxNum = 0, current = a[startX][startY];
    for (int i = 0; i < 4; i++) {
        int cnt = 0;
        int nx = startX + dx[i];
        int ny = startY + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
            if (!visit[nx][ny]) {
                cnt = Run(nx, ny, current, visit) + 1;
            }
        }

        maxNum = max(maxNum, cnt);
    }

    return maxNum;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    bool visit[MAX + 1][MAX + 1];
    cin >> n;
    const int N = n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int maxNum = 0;
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= n; j++) {
            memset(visit, false, sizeof(visit));

            maxNum = max(Run(i, j, 0, visit), maxNum);
        }
    }

    cout << maxNum << '\n';
    return 0;
}