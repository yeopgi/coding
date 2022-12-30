#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    int n = priorities.size();
    for (int i = 0; i < n; i++) {
        q.push({priorities[i], i});
    }

    sort(priorities.begin(), priorities.end(), greater<int>());

    int cnt = 0;
    while (!q.empty()) {
        int i;
        for (i = 0; i < n; i++) {
            if (q.front().first < priorities[i]) {
                q.push(q.front());
                q.pop();
                break;
            }
        }

        if (i == n) { // 가장 앞보다 더 큰 중요도가 없어서 큐의 변화가 없는 경우 -> 가장 앞은 출력되어야 한다. 그리고 cnt 1씩 증가
            cnt++;
            if (q.front().second == location) {
                answer = cnt;
                return answer;
            }

            priorities.erase(priorities.begin());
            n -= 1;
            q.pop();
        }
    }

    return answer;
}