#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

const int MAX = 10000;
int N;
int _time[MAX + 1];
int d[MAX + 1];
unordered_multimap<int, int> umm; // 선행노드 리스트

void Run(int node)
{
    for (int i = node; i <= N; i++) {
        if (umm.count(i) == 0) {
            d[i] = _time[node];
            continue;
        }

        auto range = umm.equal_range(i);
        for (auto j = range.first; j != range.second; j++) {
            int prevNode = j->second;
            d[i] = max(d[i], _time[i] + d[prevNode]);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int spend, cnt;
        cin >> spend >> cnt;
        _time[i] = spend;
        for (int j = 0; j < cnt; j++) {
            int temp;
            cin >> temp;
            umm.insert({i, temp});
        }
    }

    Run(1);

    cout << *max_element(d + 1, d + (N + 1)) << '\n';
    return 0;
}