#include <algorithm>
#include <iostream>
using namespace std;
#define INFINITE 10000000

int memory[101];
int cost[101];
int dp[101][10001];

int main(void) 
{
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
            if (j - cost[i] >= 0) 						                        // ex) 2번째 어플까지 선택했고 비용이 현재 1원인 경우를 탐색하고 있을 때,  				
                dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + memory[i]);   //     d[1][0] + memory[2] 과 d[2][1] 을 비교한다. d[1][0] 중 0은 아래와 같은 과정을 통해 도출
            }                                                                   //     2번째 어플까지 선택했고, 1원을 탐색하고 있을 경우, 1원을 만들 수 있는 경우의 수는
                                                                                //     1번째 어플까지 선택했고 0원을 탐색한 순간 + 두번째 어플의 비용을 더하면 1원이 된다.
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);				                // ex) 1번째 어플의 비용 10, 메모리 30이고,
            if (dp[i][j] >= necessaryMemory) {					                //     2번째 어플의 비용 20, 메모리 30일 경우,	
                ans = min(ans, j);						                        //     위의 경우를 대비해서 비교해준다.
            }
        }
    }

    cout << ans;
    return 0;
}

// 참고 : https://huiung.tistory.com/120
/*
    3 10
    6 4 10  // 메모리
    2 1  4  // 비용    



*/