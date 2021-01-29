#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool visit[1001];
vector<vector<int>> v;
int ret;

void Run(int src) {
    if (visit[src]) {
        return;
    }

    visit[src] = true;
    for (int i = 0; i < v[src].size(); i++) {
        Run(v[src][i]);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M; // N : 정점의 수, M : 간선의 수
    v.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int src, dst;
        cin >> src >> dst;
        v[src].emplace_back(dst);
        v[dst].emplace_back(src);
    }

    ret = 0;
    for (int i = 1; i <= N; i++) {
        if (!visit[i]) {
            ++ret;
            Run(i);
        }
    }

    cout << ret << '\n';
    return 0;
}

