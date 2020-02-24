#include <algorithm>
#include <iostream>
using namespace std;
#define INFINITE 10000000

int memory[101];
int cost[101];
int dp[101][10001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int appCnt, necessaryMemory;
    cin >> appCnt >> necessaryMemory;
    for (int i = 1; i <= appCnt; i++) {
        cin >> memory[i];
    }

    for (int i = 1; i <= appCnt; i++) {
        cin >> cost[i];
    }

    int ans = INFINITE;
    dp[0][cost[0]] = memory[0];
    for (int i = 1; i <= appCnt; i++) {
        for (int j = 0; j <= 10000; j++) {
            if (j - cost[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + memory[i]);
            }

            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (dp[i][j] >= necessaryMemory) {
                ans = min(ans, j);
            }
        }
    }

    cout << ans;
    return 0;
}

// 참고 : https://huiung.tistory.com/120