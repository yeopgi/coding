#include <iostream>
using namespace std;

int map[301][301];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }

    int i, j, x, y, k;
    cin >> k;
    while (k--) {
        cin >> i >> j >> x >> y;
        int temp = 0;
        for (int l = i; l <= x; l++) {
            for (int o = j; o <= y; o++) {
                temp += map[l][o];
            }
        }

        cout << temp << '\n';
    }

    return 0;
}