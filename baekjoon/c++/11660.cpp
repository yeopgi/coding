#include <iostream>
#include <cstring>
#include <memory>
using namespace std;

int N, M;
int x, x2, y, y2;
int map[1025][1025];
int cache[1025][1025];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int temp;
            cin >> temp;
            map[i + 1][j + 1] = map[i][j + 1] + map[i + 1][j] - map[i][j] + temp;
        }
    }

    while (M--) {
        cin >> x >> y >> x2 >> y2;
        cout << map[x2][y2] - map[x2][y - 1] - map[x - 1][y2] + map[x - 1][y - 1] << '\n';
    }

    return 0;
}