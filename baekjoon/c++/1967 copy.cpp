#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> v[10002];
bool visit[10002];
int ans = 0;
int maxNum = 0;
int endPoint = 0;

void Dfs(int current, int length)
{
    if (visit[current]) {
        return;
    }

    for (int i = 0; i < v[current].size(); i++) {
        if (!visit[v[current][i].first]) {
            int value = v[current][i].second + length;
            if (value > maxNum) {
                maxNum = value;
                Dfs(v[current][i].first, value);
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int src, dest, length;
        cin >> src >> dest >> length;
        v[src].push_back({dest, length});
        v[dest].push_back({src, length});
    }

    for (int i = 1; i <= n; i++) {
        Dfs(i, 0);
        memset(visit, false, sizeof(visit));
    }

    cout << maxNum << '\n';
}