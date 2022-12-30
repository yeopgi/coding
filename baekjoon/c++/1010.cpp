#include <iostream>
#include <cstring>
using namespace std;

int d[31][31];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, T;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 1; i <= M; i++) {
            d[1][i] = i;
        }

        for (int i = 2; i <= N; i++) {
            for (int j = i; j <= M; j++) {
                for (int k = j; k >= i; k--) {
                    d[i][j] = d[i][j] + d[i - 1][k - 1];
                }
            }
        }

        cout << d[N][M] << endl;
        memset(d, 0, sizeof(d));
    }

    return 0;
}