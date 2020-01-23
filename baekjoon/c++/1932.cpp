#include <iostream>
using namespace std;

int d[501][501];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, sum = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; i++) {
            cin >> d[i][j];
        }
    }

    

    return 0;
}