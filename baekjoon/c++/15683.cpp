#include <iostream>
#include <vector>
using namespace std;

int N, M;
const int MAX = 8;
int a[MAX + 1][MAX + 1];
vector<vector<pair<int, int>>> v;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    v.resize(6);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                v[1].push_back({i, j});
            } else if (a[i][j] == 2) {
                v[2].push_back({i, j});
            } else if (a[i][j] == 3) {
                v[3].push_back({i, j});
            } else if (a[i][j] == 4) {
                v[4].push_back({i, j});
            } else if (a[i][j] == 5) {
                v[5].push_back({i, j});
            }
        }
    }

    return 0;
}