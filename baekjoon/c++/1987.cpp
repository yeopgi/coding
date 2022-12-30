#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int R, C;
const int MAX = 20;
int a[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int alpha[26];
string str[MAX];
int ans = 0;

void Run(int srcX, int srcY, int currentCnt)
{
    ans = max(ans, currentCnt);
    for (int i = 0; i < 4; i++) {
        int nx = srcX + dx[i];
        int ny = srcY + dy[i];
        if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
            int temp = a[nx][ny] - 65;
            if (alpha[temp] == 0) {
                alpha[temp]++;
                Run(nx, ny, currentCnt + 1);
                alpha[temp]--;
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> str[i];
        for (int j = 0; j < C; j++) {
            a[i][j] = str[i][j];
        }
    }

    alpha[a[0][0] - 65]++;
    Run(0, 0, 1);
    cout << ans << '\n';
    return 0;
}