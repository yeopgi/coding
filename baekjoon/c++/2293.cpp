#include <iostream>
#include <algorithm>
using namespace std;

int coin[101], d[101];
const int INITIALIZE = 987654321;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    fill_n(coin, 101, INITIALIZE);

    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        coin[temp] = 1;
    }
    d[0] = 0;
    for (int i = 1; i <= k; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (coin[j] - i > 0) {
                continue;
            }
            if (i - coin[j] == 0) {
                cnt++;
            }
        }
    }

        return 0;
}