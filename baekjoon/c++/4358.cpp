#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, double> _map;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    double cnt = 0;
    while (getline(cin, str)) {
        cnt++;
        if (!_map.count(str)) {
            _map[str] = 1;
        } else {
            _map[str]++;
        }
    }

    cout << fixed;
    cout.precision(4);
    for (auto i : _map) {
        cout << i.first << ' ' << (_map[i.first] / cnt) * 100 << '\n';
    }

    return 0;
}