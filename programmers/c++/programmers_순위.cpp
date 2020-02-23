#include <algorithm>
#include <string>
#include <vector>
#define INFINITE 10000000
using namespace std;

int check[101][101];

int solution(int n, vector<vector<int>> results) 
{
    int answer = 0;
    fill(&check[0][0], &check[n][n + 1], INFINITE);
    for (int i = 0; i < results.size(); i++) {
        int x = results[i][0];
        int y = results[i][1];
        check[x][y] = 1;
    }
                                                                    //플로이드와샬 알고리즘에 의하면 가장 먼저 바뀌는건 도착 노드
    for (int k = 1; k <= n; k++) {                                  // 거쳐가는 노드   
        for (int i = 1; i <= n; i++) {                              // 출발 노드
            for (int j = 1; j <= n; j++) {                          // 도착 노드
                if (check[i][k] + check[k][j] < check[i][j]) {
                    check[i][j] = check[i][k] + check[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        bool isFight = true;
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                continue;
            }
                                                                                // 마지막까지 INFITINTE 인건 INFINITE > 비교대상일때, 비교대상이 INFINITE + K 이기 때문이다. ( 1<= K <= INFINITE)
            if (check[i][j] == INFINITE && check[j][i] == INFINITE) {           // [i][j] 와 [j][i]를 비교하는건 서로의 전적을 알아보기 위해서
                isFight = false;
            }
        }

        if (isFight) {
            answer++;
        }
    }

    return answer;
}