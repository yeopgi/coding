#include <string>
#include <vector>
#include <algorithm>

#define INFINITE 2147483647
using namespace std;

int check[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    fill(&check[0][0], &check[n][n + 1], 1e6);
    for (int i = 0; i <= results.size(); i++) {
        int x = results[i][0];
        int y = results[i][1];
        check[x][y] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (check[i][k] + check[k][j] < check[i][j]) {
                    check[i][j] = check[i][k] + check[k][j]; 
                }
            }
        }
    }

    for (int i = 1; i<= n; i++) {
        bool isFight = true;
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                continue;
            }

            if (check[i][j] == 1e6 && check[j][i] == 1e6) {
                isFight = false;
            }
        }

        if (isFight) {
            answer++;
        }
    }
    
    return answer;
}