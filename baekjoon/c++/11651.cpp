#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int cnt;
    cin >> cnt;

    for (int i = 1; i <= cnt; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(y, x));
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        cout << v[i].second << ' ' << v[i].first << '\n';
    }

    return 0;
}