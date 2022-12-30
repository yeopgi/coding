#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 50;
vector<char> A[MAX], B[MAX];
bool visit[MAX][MAX];
int N, M;

void Run(int row, int col)
{
    for (int i = row; i <= row + 2; i++) {
        for (int j = col; j <= col + 2; j++) {
            if (A[i][j] == '0')
                A[i][j] = '1';
            else
                A[i][j] = '0';
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < temp.size(); j++)
            A[i].push_back(temp[j]);
    }

    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < temp.size(); j++)
            B[i].push_back(temp[j]);
    }

    if (!(N >= 3 && M >= 3)) {
        bool isSame = true;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (A[i][j] != B[i][j]) {
                    isSame = false;
                }
            }
        }

        if (!isSame) {
            cout << -1 << '\n';
        } else {
            cout << 0 << '\n';
        }

        return 0;
    }

    int cnt = 0;
    bool isSame = false;
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 2; j++) {
            isSame = true;
            if (A[i][j] != B[i][j]) {
                Run(i, j);

                cnt++;
            }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (A[i][j] != B[i][j]) {
                        isSame = false;
                    }
                }
            }
        }

        if (isSame == true) {
            cout << cnt << '\n';
            return 0;
        }
    }

    if (!isSame)
        cout << -1 << '\n';

    return 0;
}