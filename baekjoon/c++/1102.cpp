#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 16 + 1;
int N, P;
int d[MAX];
int plant[MAX][MAX];
string isRunning;
const int INF = 987654321;
int cache[MAX][1 << MAX];
string currentState;

int CountSetBits(int n)
{
    int cnt = 0;
    while (n) {
        cnt += n & 1;
        n >>= 1;
    }

    return cnt;
}

int minCost(int idx, int curState) {
    if (CountSetBits(curState) - 1 >= P)
        return 0;

    int &result = cache[idx][curState];
    if (result != -1)
        return result;

    result = INF;
    for (int i = 0; i < N; i++)
        if ((curState & (1 << i)) == 0) //꺼진 발전소를 찾고
        {
            int nextState = curState | (1 << i); //해당 발전소를 켰다고 가정
            for (int j = 0; j < N; j++)
                if ((nextState & (1 << j))) //해당 발전소를 킨 다음 단계로 이동
                    result = min(result, plant[idx][i] + minCost(j, nextState));
        }

    return result;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> plant[i][j];
        }
    }

    cin >> currentState;
    int bit = 1 << MAX;
    for (int i = 0; i < currentState.size(); i++) {
        if (currentState[i] == 'Y') {
            bit |= (1 << i);
        }
    }

    cin >> P;
    if (P == 0) {
        cout << 0 << '\n';
    } else {
        memset(cache, -1, sizeof(cache));

        int result = INF;
        for (int i = 0; i < N; i++) {
            if (currentState[i] == 'Y') {
                result = min(result, minCost(i, bit));
            }
        }

        if (result == INF) {
            cout << -1 << '\n';
        } else {
            cout << result << '\n';
        }
    }

    return 0;
}