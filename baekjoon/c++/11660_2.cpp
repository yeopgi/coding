#include <cstring>
#include <iostream>
#include <memory>
using namespace std;

int n, m;
int x, x2, y, y2;
int numbers[1025][1025];
int dp[1025][1025];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= n; ++j) {
            cin >> numbers[i][j];
        }
    }

    while (m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        dp[x1][y1] = numbers[x1][y1];
        for (size_t i = y1 + 1; i <= y2; ++i) {
            dp[x1][i] = numbers[x1][i] + dp[x1][i - 1];
        }

        for (size_t i = x1 + 1; i <= x2; ++i) {
            dp[i][y1] = numbers[i][y1] + dp[i - 1][y1];
        }

        for (size_t i = x1 + 1; i <= x2; ++i) {
            for (size_t j = y1 + 1; j <= y2; ++j) {
                dp[i][j] = numbers[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            }
        }

        cout << dp[x2][y2] << '\n';
        // for (size_t i = 1; i <= n; ++)

        // memset(dp, 0x00, sizeof(dp));
    }

    return 0;
}