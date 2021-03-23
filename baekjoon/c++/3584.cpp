#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10000;
vector<vector<int>> v[MAX + 1];
int N; // 노드의 수

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> N;
        for (int i = 1; i < N; i++)
        {
            int parent, child;
            cin >> parent >> child;
            v[parent].emplace_back(child);
        }

        int node1, node2;
        cin >> node1 >> node2;
        //Run();
    }

    return 0;
}