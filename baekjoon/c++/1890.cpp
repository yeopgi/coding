#include <iostream>
#include <cstring>
using namespace std;

int N;
int a[101][101];
long long cache[101][101];

long long Run(int x, int y)
{
    if (y == N && x == N) {
        return 1;
    }

    long long &result = cache[x][y];
    if (result != -1) {
        return result;
    }

    result = 0;
    if (x != N && x + a[x][y] <= N) {
        result += Run(x + a[x][y], y);
    }

    if (y != N && y + a[x][y] <= N) {
        result += Run(x, y + a[x][y]);
    }

    return result;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> a[i][j];
        }
    }

    memset(cache, -1, sizeof(cache));

    long long ans = Run(1, 1);
    cout << ans << '\n';
    return 0;
}