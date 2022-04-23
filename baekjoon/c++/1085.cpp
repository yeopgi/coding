#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x,y,w,h;
    cin >> x >> y >> w >> h;
    if(min(min(min(w - x, h - y), x - 0), y - 0) == 0) {
        cout << w - x << '\n';
    } else {
        cout << min(min(min(w - x, h - y), x - 0), y - 0);
    }

    return 0;
}