#include <iostream>
#include <cstring>
#include <memory>
using namespace std;

int n, m;
int numbers[1024+1][1025];
int dp[1024+1][1025];
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (size_t i = 1; i <=n; ++i) {
        for (size_t j = 1; j <= n; ++j) {
            cin >> numbers[i][j];
        }
    }


}