#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int MAX = 10000;
int N;
int _time[MAX + 1];
int d[MAX + 1];
int laterNodeCnt[MAX + 1];
int emptyNode = 0;
unordered_multimap<int, int> umm; // 선행노드 리스트

int Run(int node)
{
    int maxNum = 0;
    for (int i = node; i <= N; i++) {
        if (umm.count(i) == 0) {                    // 내 앞에 선행노드가 없다면
            d[i] = _time[i];                     // 나 자신의 시간이 최대시간
            if (laterNodeCnt[i] == 0) {             // 근데 내 후행노드까지 없다면
                emptyNode = max(emptyNode, d[i]);   // 나는 독립적으로 수행됨
            }

            continue;
        }

        auto range = umm.equal_range(i);
        for (auto j = range.first; j != range.second; j++) {
            int prevNode = j->second;
            d[i] = max(d[i], _time[i] + d[prevNode]);
            maxNum = max(d[i], maxNum);
        }
    }

    return max(maxNum, emptyNode);
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
            umm.insert({i, temp});  // i : 현재 노드, temp : 선행 노드
            laterNodeCnt[temp]++;
        }
    }

    cout << Run(1) << '\n';
    return 0;
}