#include <iostream>
#include <algorithm>
using namespace std;

int N;
int a[12];
int opr[4];
int minNum = 100000000 + 1 , maxNum = -100000000 - 1;

void Run(int plus, int minus, int multiple, int divide, int idx, int result) // 1 0 opr배열
{
    if (idx == N) {
        maxNum = max(maxNum, result);
        minNum = min(minNum, result);
        return;
    }

    if (plus > 0) {
        Run(plus - 1, minus, multiple, divide, idx + 1, result + a[idx + 1]);
    }

    if (minus > 0) {
        Run(plus, minus - 1, multiple, divide, idx + 1, result - a[idx + 1]);
    }

    if (multiple > 0) {
        Run(plus, minus, multiple - 1, divide, idx + 1, result * a[idx + 1]);
    }

    if (divide > 0) {
        Run(plus, minus, multiple, divide - 1, idx + 1, result / a[idx + 1]);
    }
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> opr[i];
    }

    Run(opr[0], opr[1], opr[2], opr[3], 1, a[1]);

    cout << maxNum << '\n';
    cout << minNum << '\n';
    return 0;
}