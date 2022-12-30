#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E, start;
const int INF = 987654321;
vector<int> v2[5];
vector<pair<int, int>> v[20001];
priority_queue<pair<int, int>> pq;

vector<int> Run(int start)
{
    vector<int> dist(V + 1, INF);
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int src = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (cost > dist[src]) {
            continue;
        }

        for (int i = 0; i < v[src].size(); i++) {
            int dst = v[src][i].second;
            int costTemp = v[src][i].first + cost; // v[src]까지의 최단거리
            if (dist[dst] > costTemp) {
                dist[dst] = costTemp;
                pq.push({-dist[dst], dst});
            }
        }
    }

    return dist;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> V >> E;
    cin >> start;
    for (int i = 1; i <= E; i++) {
        int src, dst, weight;
        cin >> src >> dst >> weight;
        v[src].push_back({weight, dst});
    }

    vector<int> ans = Run(start);
    ans[start] = 0;
    for (int i = 1; i <= V; i++) {
        if (ans[i] == INF) {
            cout << "INF" << '\n';
            continue;
        }

        cout << ans[i] << '\n';
    }

    return 0;
}