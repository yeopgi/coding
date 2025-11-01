#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int d[101][100001];
int weight[101], value[101];
int n;
int k;
vector<pair<int, int>> items;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    items.reserve(n + 1);
    for (size_t i = 1; i <= n; ++i){
        int W, V;
        cin >> W >> V;
        items[i] = {W, V};
    }

    int ans = 0;
    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= k; ++j){
            if (j < items[i].first) {
                d[i][j] = d[i-1][j];

            } else{
                d[i][j] = max(d[i- 1][j - items[i].first] + items[i].second, d[i-1][j]);
            }

            ans = max(ans, d[i][j]);
        }
    }

    cout << ans << '\n';
    return 0;

}
