#include <cstring>
#include <iostream>
using namespace std;

const int MAX = 501;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N, M;
int map[MAX][MAX];
int d[MAX][MAX];

int Run(int currentX, int currentY) {
    if (currentX == N && currentY == M) {
        return 1;
    }

    int &result = d[currentX][currentY];
    if (result != -1) {
        return result;
    }

    result = 0;
    for (int i = 0; i < 4; i++) {
        int nextX = currentX + dx[i];
        int nextY = currentY + dy[i];
        if (nextX >= 1 && nextX <= N && nextY >= 1 && nextY <= M) {
            if (map[nextX][nextY] < map[currentX][currentY]) {
                result += Run(nextX, nextY);
            }
        }
    }

    return result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }

    memset(d, -1, sizeof(d));

    cout << Run(1, 1) << '\n';
    return 0;
}