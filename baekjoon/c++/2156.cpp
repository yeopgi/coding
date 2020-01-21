#include <iostream>
#include <algorithm>
using namespace std;

int d[10000 + 1][10000 + 1];
int a[10000 + 1][10000 + 1];
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int glass;
    cin >> glass;
    for (int i = 1; i <= glass; i++) {
        cin >> a[0][i];
    }
}