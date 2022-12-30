#include <string>
#include <vector>

using namespace std;

int d[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    d[1][1] = 1;
    for (int i = 0; i < puddles.size(); i++) {
        d[puddles[i][1]][puddles[i][0]] = -1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (d[i][j] == -1) {
                d[i][j] = 0;
            } else {
                if (i == 1) {
                    d[i][j] += 1;
                } else {
                    d[i][j] = (d[i - 1][j] + d[i][j - 1]) % 1000000007;
                }
            }

            if (j == m) {
                answer = d[i][j];
            }
        }
    }
        return answer;
}