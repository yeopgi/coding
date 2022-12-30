#include <array>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000;
int N, K;
int d[MAX + 1];
array<int, MAX + 1> spend;
vector<int> connection[MAX + 1];

int Run(int dst)
{
    if (d[dst] != -1) {
        return d[dst];
    }

    if (connection[dst].size() == 0) { // 시작 가능
        d[dst] = spend[dst];
        return d[dst];
    } else {
        for (int j = 0; j < connection[dst].size(); j++) {
            int temp = spend[dst] + Run(connection[dst][j]);
            d[dst] = max(d[dst], temp);
        }
    }

    return d[dst];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (int i = 1; i <= N; i++) {
            cin >> spend[i];
            d[i] = -1;
        }

        for (int i = 1; i <= K; i++) {
            int temp1, temp2;
            cin >> temp1 >> temp2;
            connection[temp2].push_back(temp1); // temp2의 선행노드는 temp1
        }

        int dst;
        cin >> dst;
        int ans = Run(dst);
        cout << ans << '\n';
        for (int i = 1; i <= N; i++) {
            connection[i].clear();
            d[i] = 0;
        }
    }

    return 0;
}