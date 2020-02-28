#include <iostream>
using namespace std;

int col, row;
int d[301];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> col >> row;
    d[0] = 1, d[1] = 2, d[2] = 3, d[3] = 4, d[4] = 5;
    cout << col * row - 1 << '\n';
    
    return 0;
}