#include <iostream>
#include <cstring>
using namespace std;

int d[1001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, list[1001];
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> list[i];
    }

    int max = 0;
    for (int i = 1; i <= N; i++) {
        d[i] = list[i];
        for (int j = 1; j < i; j++) {
            if (list[j] < list[i] && d[i] < d[j] + list[i]) {
                d[i] = d[j] + list[i];
            }

            if (max < d[i]) {
                max = d[i];
            }
        }
    }

    return 0;
}