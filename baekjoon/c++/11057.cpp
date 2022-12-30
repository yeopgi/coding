#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int d[10001][10];
const int mod = 10007;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    for (int i = 0; i < 10; i++) {
        d[1][i] = 1;
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k <= j; k++) {
                d[i][j] = d[i][j] + d[i - 1][k];
                d[i][j] %= mod;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += d[N][i];
    }
    cout << ans % mod << '\n';
    return 0;
}