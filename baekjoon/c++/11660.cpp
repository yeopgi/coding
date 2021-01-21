#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int x1, x2, y1, y2;
int map[1025][1025];
int cache[1025][1025];

int Run(int startX, int startY)
{
    if (startX > x2 || startX < 1 || startY > y2 || startY < 1) {
        return 0;
    }

    int &result = cache[startX][startY];
    if (result != -1) {
        return 0;
    }

    result = 0;
    if (startX == x2 && startY == y2) {
        result = map[startX][startY];
        return result;
    }

    result = Run(startX + 1, startY) + Run(startX, startY + 1) + Run(startX + 1, startY + 1);
    result += map[startX][startY];
    return result;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }

    while (M--) {
        memset(cache, -1, sizeof(cache));
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2 && y1 == y2) {
            cout << map[x1][y1] << '\n';    //  ex) [4,4] ~ [4,4]
        } else {
            cout << Run(x1, y1) << '\n';
        }
    }

    return 0;
}