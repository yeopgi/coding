
#include <iostream>
using namespace std;

int N, M;
int map[1001][1001];
int cache[1001][1001];
int dx[3] = {0, 1, 1};
int dy[3] = {1, 0, 1};

void Run(int x, int y)
{
    if (x == N && y == M) {
        return;
    }

    for (int i = 0; i < 3; i++) {
        int xTemp = x + dx[i];
        int yTemp = y + dy[i];
        if (xTemp <= N && xTemp >= 1 && yTemp <= M && yTemp >= 1) {
            int temp = map[xTemp][yTemp] + cache[x][y];
            if (temp > cache[xTemp][yTemp]) {
                cache[xTemp][yTemp] = temp;

                Run(xTemp, yTemp);
            }

            return;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }

    cache[1][1] = map[1][1];
    Run(1, 1);

    cout << cache[N][M] << '\n';
    return 0;
}
