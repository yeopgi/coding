#include <iostream>
using namespace std;

int T;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    if ((T % 10)) {
        cout << -1 << '\n';
        return 0;
    }

    pair<int, int> value[3] = {{60 * 5,0}, {60, 0}, {10, 0}};
    while (T > 0) {
        for (int i = 0; i < 3; i++) {
            if (T >= value[i].first) {
                T -= value[i].first;
                value[i].second++;
                break;
            }
        }
    }

    for (auto i : value)
        cout << i.second << ' ';

    cout << '\n';
    return 0;
}