#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

void Dfs(int start);
void Bfs(int start);

bool visit[10000 + 1];
vector<vector<int>> v;
queue<int> q;
int vertex, edge, startVertex;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> vertex >> edge >> startVertex;
    v.resize(vertex + 1);
    
    while (edge--) {
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }

    for (int i = 0; i < vertex; i++) {
        sort(v[i].begin(), v[i].end());
    }

    Dfs(startVertex);

    cout << '\n';
    fill_n(visit, vertex + 1, false);
    
    Bfs(startVertex);

    return 0;
}

void Dfs(int start)
 {
    visit[start] = true;
    cout << start << ' ';
    for (int i = 0; i < v[start].size(); i++) {
        if (!visit[v[start][i]]) {
            Dfs(v[start][i]);
        }
    }
}

void Bfs(int start)
{
    q.push(start);
    visit[start] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << ' ';
        for (int y : v[x]) {
            if (!visit[y]) {
                q.push(y);
                visit[y] = true;
            }
        }
    }
}
