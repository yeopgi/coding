#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
const int MAX = 100000 + 1;
int d[3][4];
int arr[MAX][4];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }

    for (int i = 1; i <= N; i++) {
        int cur = i % 2;
        int prev = (i - 1) % 2;
        d[cur][1] = max(d[prev][1], d[prev][2]) + arr[i][1];
        d[cur][2] = max(d[prev][3], max(d[prev][1], d[prev][2])) + arr[i][2];
        d[cur][3] = max(d[prev][3], d[prev][2]) + arr[i][3];
    }

    int maxNum = max(max(d[N % 2][1], d[N % 2][2]), d[N % 2][3]);
    memset(d, 0, sizeof(d));

    for (int i = 1; i <= N; i++) {
        int cur = i % 2;
        int prev = (i - 1) % 2;
        d[cur][1] = min(d[prev][1], d[prev][2]) + arr[i][1];
        d[cur][2] = min(d[prev][3], min(d[prev][1], d[prev][2])) + arr[i][2];
        d[cur][3] = min(d[prev][3], d[prev][2]) + arr[i][3];
    }

    int minNum = min(min(d[N % 2][1], d[N % 2][2]), d[N % 2][3]);
    cout << maxNum << ' ' << minNum << '\n';
    return 0;
}