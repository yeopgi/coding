#include <iostream>
#include <algorithm>
using namespace std;

int d[1000 + 1][3 + 1];
int rgb[1000 + 1][4];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int houseCnt;
    cin >> houseCnt;
    for (int i = 1; i <= houseCnt; i++) {
        for (int j = 1; j < 4; j++) {
            cin >> rgb[i][j];
        }
    }
    
    for (int i = 1; i <= houseCnt; i++) {
        d[i][1] = min(d[i - 1][2], d[i - 1][3]) + rgb[i][1];
        d[i][2] = min(d[i - 1][1], d[i - 1][3]) + rgb[i][2];
        d[i][3] = min(d[i - 1][2], d[i - 1][1]) + rgb[i][3];
    }

    cout << min(min(d[houseCnt][1], d[houseCnt][2]), d[houseCnt][3]) << '\n';
    return 0;
}