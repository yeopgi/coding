#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> v[10002];
bool visit[10002];
int maxNum = 0;
int furthest;

void Dfs(int current, int length)
{
    if (visit[current]) {
        return;
    }

    visit[current] = true;
    for (int i = 0; i < v[current].size(); i++) {
        if (!visit[v[current][i].first]) {
            int value = v[current][i].second + length;
            if (value > maxNum) {
                maxNum = value;
                furthest = v[current][i].first;
            }

            Dfs(v[current][i].first, value);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int src, dest, length;
        cin >> src >> dest >> length;
        v[src].push_back({dest, length});
        v[dest].push_back({src, length});
    }

    Dfs(1, 0);
    memset(visit, false, sizeof(visit));
    Dfs(furthest, 0);

    cout << maxNum << '\n';
}