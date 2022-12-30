#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100000;
vector<pair<int, int>> v[MAX + 1];
int V;
bool visit[MAX + 1];
int maxLength[MAX + 1];
int maxNum = 0;
int farthestNode = 0;
int diameter = 0;

void Run(int src, int length)
{
    if (visit[src]) {
        return;
    }

    visit[src] = true;
    if (diameter < length) {
        diameter = length;
        farthestNode = src;
    }

    for (int i = 0; i < v[src].size(); i++) {
        int adj = v[src][i].first;
        int adjLength = v[src][i].second;
        Run(adj, length + adjLength);
    }
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> V;
    for (int i = 1; i <= V; i++) {
        int startNode;
        cin >> startNode;
        while (true) {
            int adj, length;
            cin >> adj;
            if (adj == -1) {
                break;
            }

            cin >> length;
            v[startNode].push_back({adj, length});
        }
    }

    memset(visit, false, sizeof(visit));
    Run(1, 0);              // 트리의 루트는 어떤 노드라도 가능

    diameter = 0;
    memset(visit, false, sizeof(visit));
    Run(farthestNode, 0); // 트리의 루트는 어떤 노드라도 가능

    cout << diameter << '\n';
    //cout << *max_element(maxLength, maxLength + (V + 1)) << '\n';
    return 0;
}