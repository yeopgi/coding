#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321

int memory[101];
int cost[101];
int dp[101][10001];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N,M; cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> memory[i];
    for(int i = 0; i < N; i++)
        cin >> cost[i];

    int ans = INF;

    dp[0][cost[0]] = memory[0];
    for(int i = 1; i < N; i++) {
        for(int j = 0; j <= 10000; j++) {
                if(j-cost[i] >= 0)
                    dp[i][j] = max(dp[i][j], dp[i-1][j-cost[i]]+memory[i]);

                dp[i][j] = max(dp[i][j], dp[i-1][j]);

                if(dp[i][j] >= M) {
                    ans = min(ans, j);
                }
        }
    }
    cout<<ans;
    return 0;
}