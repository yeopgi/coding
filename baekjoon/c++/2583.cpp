#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100 + 1;
int N, M, K;
int a[MAX][MAX];
bool visit[MAX][MAX];
int dx[4] = {0,0 , -1, 1};
int dy[4] = {1,-1 , 0, 0};
int cnt = 0;

void Run(int startX, int startY)
{
    if (visit[startX][startY]) {
        return;
    }

    visit[startX][startY] = true;
    cnt++;
    a[startX][startY] == 1;
    for (int i = 0; i < 4; i++) {
        int nextX = startX + dx[i];
        int nextY = startY + dy[i];
        if (nextX >= 0 && nextX < M && nextY >= 0 && nextY < N) {
            if (!visit[nextX][nextY] && a[nextX][nextY] == 0) {
                Run(nextX, nextY);
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        int belowX, belowY, aboveX, aboveY;
        cin >> belowX >> belowY >> aboveX >> aboveY;
        for (int j = belowY; j < aboveY; j++) {
            for (int k = belowX; k < aboveX; k++) {
                a[j][k] = 1;
            }
        }
    }

    int sector = 0;
    vector<int> v;
    for (int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cout << a[i][j] << ' ';
            if (a[i][j] == 0 && !visit[i][j]) {
                Run(i, j);
                sector++;
                v.emplace_back(cnt);
                cnt = 0;
            }
        }

        cout << '\n';
    }

    cout << sector << '\n';
    sort(v.begin(), v.end());

    for (auto i : v) {
        cout << i << ' ';
    }

    cout << '\n';
    return 0;
}