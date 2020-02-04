#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

void Dfs(int start);
void Bfs(int start);

bool visit[10000 + 1];
vector<vector<int>> v;
queue<int> q;
int vertex, edge, startVertex;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> vertex >> edge >> startVertex;
    v.resize(vertex + 1);
    for(int i = 0; i < vertex + 1; i++) {
        v[i].resize(vertex + 1);
    }

    while (edge--) {
        int from, to;
        cin >> from >> to;
        v[from][to] = to;
        v[to][from] = from;
    }

    Dfs(startVertex);

    cout << '\n';
    fill_n(visit, 10001, false);

    Bfs(startVertex);

    return 0;
}

void Dfs(int start) 
{
    visit[start] = true;
    cout << start << ' ';
    for (int i = 1; i < v[start].size(); i++) {
        if (v[start][i] != 0) {
            if (!visit[v[start][i]]) {
                Dfs(v[start][i]);
            }
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
        for (int i = 1; i < v[x].size(); i++) {
            int temp = v[x][i];
            if (temp != 0) {
                if (!visit[temp]) {
                    q.push(temp);
                    visit[temp] = true;
                }
            }
        }
    }
}