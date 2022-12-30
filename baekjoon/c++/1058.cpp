#include <iostream>
#include <algorithm>
#define INFINITE 10000000

using namespace std;

int resultMap[51][51];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt, temp;
    cin >> cnt;
    for (int i = 1; i <= cnt; i++) {
        for (int j = 1; j <= cnt; j++) {
            cin >> temp;
            if (temp == 'Y') {
                resultMap[i][j] = 1;
            } else {
                resultMap[i][j] = INFINITE;
            }
        }
    }

    for (int k = 1; k <= cnt; k++) {         // 거쳐가는 노드
        for (int i = 1; i <= cnt; i++) {     // 출발 노드
            for (int j = 1; j <= cnt; j++) { // 도착 노드
                if (resultMap[i][k] + resultMap[k][j] < resultMap[i][j]) {
                    resultMap[i][j] = resultMap[i][k] + resultMap[k][j];
                    cout << "resultMap"
                         << " : " << resultMap[i][j] << endl;
                }
            }
        }
    }

    int maxNum = 0;
    
    for (int i = 1; i <= cnt; i++) {
        int result = 0;
        for (int j = 1; j <= cnt; j++) {
            if (i == j) {
                continue;
            }

            if (resultMap[i][j] <= 2) {
                result++;
            }
        }

        maxNum = max(maxNum, result);
    }
    
    cout << maxNum << '\n';
    return 0;
}