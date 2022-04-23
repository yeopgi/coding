#include <iostream>
using namespace std;

int col, row;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> col >> row;
    cout << col * row - 1 << '\n';

    return 0;
}