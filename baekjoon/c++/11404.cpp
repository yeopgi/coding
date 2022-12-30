#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int map[101][101];
const int INF = 987654321;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            map[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int start, dest, cost;
        cin >> start >> dest >> cost;
        if (map[start][dest] > cost)
            map[start][dest] = cost;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (map[j][i] != INF && map[i][k] != INF)
                    map[j][k] = min(map[j][i] + map[i][k], map[j][k]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || map[i][j] == INF) {
                cout << 0 << ' ';
                continue;
            }
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}