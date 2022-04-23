#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

const int INF = 987654321;
const int MAX = 100000 + 1;

int N;
vector<int> graph[MAX];
int parent[MAX];
bool visit[MAX];

void Run(int cur)
{
	visit[cur] = true;
	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i];
		if (!visit[next]) {
			parent[next] = cur;	// next parent는 cur이다.
			Run(next);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int node1, node2;
		cin >> node1 >> node2;
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}

	Run(1); // 1이 루트이므로 이곳에서부터 탐색 시작

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}

	return 0;
}