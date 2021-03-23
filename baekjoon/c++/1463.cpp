#include <iostream>
using namespace std;

int dp[1000000 + 1];

int go(const int n)
{
    if(n == 1) {
        return 0;
    }

    if(dp[n] > 0) return dp[n];

    dp[n] = go(n-1) + 1;
    if(n % 3 == 0) {
        int temp = go(n / 3) + 1;
        if(dp[n] > temp) {
            dp[n] = temp;
        }
    }

    if(n % 2 == 0) {
        int temp = go(n / 2) + 1;
        if(dp[n] > temp) {
            dp[n] = temp;
        }
    }

    return dp[n];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    go(n);

    cout << go(n) << '\n';
    return 0;
}