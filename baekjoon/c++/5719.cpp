#include <iostream>
#include <vector>
#include <queue>
#include <cstring> //memset
using namespace std;

const int MAX = 500;
const int INF = 987654321;
int N, M;
vector<pair<int, int>> graph[MAX];
vector<pair<int, int>> trace[MAX];
bool visited[MAX][MAX];

vector<int> dijkstra(int start, int vertex)
{
    vector<int> distance(vertex, INF); 
    distance[start] = 0; 
    priority_queue<pair<int, int>> pq; 
    pq.push(make_pair(0, start)); 
       while (!pq.empty()) {
        int cost = -pq.top().first; //거리의 부호를 바꾸어 거리가 작은 정점부터 꺼내지게
        int curVertex = pq.top().second;
        pq.pop();

        if (distance[curVertex] < cost)
            continue;

        for (int i = 0; i < graph[curVertex].size(); i++) {
            int neighbor = graph[curVertex][i].first;
            int neighborDistance = cost + graph[curVertex][i].second;
            //거의 최단 거리를 찾기위해 삭제된 정점간의 간선을 무시한다
            if (graph[curVertex][i].second == -1)
                continue;

            //최소 경로 발견시 업데이트

            if (distance[neighbor] > neighborDistance) {
                distance[neighbor] = neighborDistance;
                pq.push(make_pair(-neighborDistance, neighbor));
                trace[neighbor].clear();
                trace[neighbor].push_back(make_pair(curVertex, neighborDistance));
            } else if (distance[neighbor] == neighborDistance)
                trace[neighbor].push_back(make_pair(curVertex, neighborDistance));
        }
    }

    return distance;
}

void BFS(int destination)
{
    queue<int> q;
    q.push(destination);

    while (!q.empty()) {
        int curVertex = q.front();
        q.pop();

        for (int i = 0; i < trace[curVertex].size(); i++) {
            int neighbor = trace[curVertex][i].first;
            if (visited[curVertex][neighbor])
                continue;

            for (int i = 0; i < graph[neighbor].size(); i++)
                if (graph[neighbor][i].first == curVertex)
                    graph[neighbor][i].second = -1;

            q.push(neighbor);
        }
    }
}

int main(void)
{
    while (1) {
        memset(visited, false, sizeof(visited));
        memset(trace, 0, sizeof(trace));

        for (int i = 0; i < MAX; i++)
            graph[i].clear();

        cin >> N >> M;
        if (N == 0 && M == 0)
            break;

        int S, D;
        cin >> S >> D;
        for (int i = 0; i < M; i++) {
            int source, destination, cost;
            cin >> source >> destination >> cost;
            graph[source].push_back(make_pair(destination, cost));
        }

        dijkstra(S, N);

        BFS(D);

        vector<int> result = dijkstra(S, N);
        if (result[D] == INF)
            cout << -1 << endl;
        else
            cout << result[D] << endl;
    }

    return 0;
}