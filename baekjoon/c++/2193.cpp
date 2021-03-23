// 범위초과
#include <iostream>
using namespace std;

int d[91][2];
 
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int length;
    cin >> length;

    d[1][0] = 0;
    d[1][1] = 1;
    d[2][0] = 1;
    d[2][1] = 0;
    d[3][1] = 1;
    d[3][0] = 1;
    d[3][2] = d[3][1] + d[3][0];
    int cnt = 2;
    for (int i = 4; i <= length; i++) {
        d[i][1] = d[i - 1][0];
        d[i][0] = d[i-1][1] + d[i-1][0];  
        cnt = d[i][1] + d[i][0];
    }    

    cout << cnt << '\n';
    return 0;
}