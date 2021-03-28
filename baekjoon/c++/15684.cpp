#include <iostream>
#include <vector>
using namespace std;

int N, M, H;
int a[31][11];
vector<pair<pair<int, int>, int>> rowLine;
int dy[2] = {-1, 1};
int dx[2] = {0, 1};
int ans = 987654321;
bool isPossible = false;
bool flag = false;
int bridgeCnt;

void Run(int startRow, int cnt)
{
    if (flag) {
        return;
    }

    if (cnt == bridgeCnt) { // 브릿지 갯수가 입력 브릿지 갯수랑 같다.
        bool isPossible = true;
        for (int i = 1; i <= N; i++) {
            int col = i;
            for (int j = 0; j < H; j++) {
                if (a[j][col]) {
                    col += 1;
                } else if (a[j][col - 1] && col > 1) {
                    col -= 1;
                }
            }

            if (col != i) {
                isPossible = false;
                break;
            }
        }

        if (isPossible) {
            flag = true;

        }
        return;
    }

    for (int i = startRow; i < H; i++) {
        for (int j = 1; j < N; j++) {
            if (!a[i][j - 1] && !a[i][j] && !a[i][j + 1]) {
                a[i][j] = true;
                Run(i, cnt + 1);

                a[i][j] = false;
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> H;
    for (int i = 0; i < M; i++) {
        int row, b;
        cin >> row >> b;
        a[row - 1][b] = 1;
    }

    for (int i = 0; i <= 3; i++) {
        bridgeCnt = i;
        Run(0, 0);
        if (flag) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
    return 0;
}