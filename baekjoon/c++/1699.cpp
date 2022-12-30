#include <iostream>
#include <algorithm>
using namespace std;

int d[100001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int natural;
    cin >> natural;
    d[0] = 0, d[1] = 1, d[2] = 2, d[3] = 3;
    for (int i = 4; i <= natural; i++) {
        d[i] = i;
        for (int j = 2; j * j <= i; j++) {
            d[i] = min(d[i], d[i - (j * j)] + 1);
        }
    }

    cout << d[natural] << endl;
    return 0;
}