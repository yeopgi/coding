#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 500;
int a[MAX + 1][MAX + 1];
int cache[MAX + 1][MAX + 1];
int n;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int Run(int startX, int startY)
{
    int &result = cache[startX][startY];
    if (result != -1) {
        return result;
    }

    result = 1;
    int current = a[startX][startY];
    for (int i = 0; i < 4; i++) {
        int temp = 0;
        int nx = startX + dx[i];
        int ny = startY + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
            if (current < a[nx][ny]) {
                temp = Run(nx, ny) + 1;
                result = max(temp, result);
            }
        }
    }

    return result;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    memset(cache, -1, sizeof(cache));

    int ans = 0;
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= n; j++) {
            int temp = Run(i,j);
            ans = max(ans, temp);
        }
    }

    cout << ans << '\n';
    return 0;
}