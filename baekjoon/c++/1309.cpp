#include <iostream>
using namespace std;

int N;
const int MOD = 9901;
const int MAX = 100000;
int d[MAX + 1][3]; // 0 -> 없다 1 -> 왼쪽에 있다, 2 -> 오른쪽에 있다.

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    d[1][0] = d[1][1] = d[1][2] = 1;
    for (int i = 2; i <= N; i++) {
        d[i][0] = (d[i - 1][0] + d[i - 1][1] + d[i - 1][2]) % MOD;
        d[i][1] = (d[i - 1][0] + d[i - 1][2]) % MOD;
        d[i][2] = (d[i - 1][0] + d[i - 1][1]) % MOD;
    }

    cout << d[N][0] + d[N][1] + d[N][2] << '\n';
    return 0;
}