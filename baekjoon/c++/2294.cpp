#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <cstring>
using namespace std;

int d[100001];
int value[100];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int kind, total;
    cin >> kind >> total;
    memset(d, INT_MAX, sizeof(d));

    d[0] = 0;
    for (int i = 0; i < kind; i++) {
        cin >> value[i];
        d[value[i]] = 1;
    }

    for (int i = 1; i <= total; i++) {
        for (int j = 0; j < kind; j++) {
            if (d[i] == 1) {
                break;
            }

            if (i - value[j] < 0 || d[i - value[j]] == INT_MAX) {
                continue;
            }

            d[i] = min(d[i], 1 + d[i - value[j]]);
        }
    }

    if (d[total] == INT_MAX) {
        cout << -1 << '\n';
    } else {
        cout << d[total] << '\n';
    }

    return 0;
}