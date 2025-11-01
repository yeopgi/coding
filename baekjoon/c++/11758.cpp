#include <iostream>
using namespace std;

typedef struct{
    int x;
    int y;
} Point;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Point p[3];
    for (int i = 0; i < 3; i++) {
        cin >> p[i].x >> p[i].y;
    }

    const int tmp1 = (p[1].x * p[2].y) - (p[1].x * p[1].y) - (p[0].x * p[2].y) + (p[0].x * p[1].y);
    const int tmp2 = (p[1].y * p[2].x)- (p[1].y * p[1].x) - (p[0].x * p[2].x) + (p[0].y * p[1].x);
    // const int tmp1 = (p[1].x - p[0].x) * (p[2].y - p[1].y);
    // const int tmp2 = (p[1].y - p[0].y) * (p[2].x - p[1].x);
    const int tmp3 = tmp1 - tmp2;
    if (tmp3 > 0) {
        cout << 1 <<'\n';
    } else if (tmp3 < 0) {
        cout << -1 << '\n';
    } else {
        cout << 0 << '\n';
    }
}