#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
vector<pair<int, int>> v[10002];
bool visit[10002];
int ans = 0;
int endPoint = 0;

void Dfs(int point, int length)
{
    if (visit[point]) {
        return;
    }
    visit[point] = true;
    if (ans < length) {
        ans = length;
        endPoint = point;
    }
    for (int i = 0; i < v[point].size(); i++) {
        Dfs(v[point][i].first, length + v[point][i].second);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        v[src].push_back({dest, weight});
        v[dest].push_back({src, weight});
    }
    Dfs(1, 0);

    ans = 0;
    memset(visit, false, sizeof(visit));

    Dfs(endPoint, 0);

    cout << ans << '\n';
    return 0;
}