#include <cstring>
#include <iostream>
using namespace std;

const int MAX = 200;
const int MOD = 1000000000;

int N, K;
int cache[MAX + 1][MAX + 1]; //K, N

int numOfSum(void) {
    for (int i = 0; i <= N; i++) {
        cache[1][i] = 1; //K=1인 경우 1가지
    }

    for (int i = 1; i <= K; i++)
        for (int j = 0; j <= N; j++)
            for (int l = 0; l <= j; l++)
                cache[i][j] = (cache[i][j] + cache[i - 1][j - l]) % MOD;

    return cache[K][N] % MOD;
}

int main(void) {
    cin >> N >> K;
    cout << numOfSum() << endl;
    return 0;
}