#include <iostream>
using namespace std;

int d[1001][1001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (i == j || j == 0)
                d[i][j] = 1;
            else {
                d[i][j] = (d[i - 1][j] + d[i - 1][j - 1]) % 10007;
            }
        }
    }

    cout << d[N][K] << '\n';
    return 0;
}