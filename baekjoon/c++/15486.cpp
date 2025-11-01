#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int N;
array<pair<int, int>, 1500005> nums;
array<int, 1500005> dp = {0};
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int a, b;
        cin >> a >> b;
        nums[i] = {a, b};
    }
    for (size_t i = N; i >= 1; --i)
    {
        if (i + nums[i].first <= N + 1)
        {
            dp[i] = max(dp[i + nums[i].first] + nums[i].second, dp[i + 1]);
        }
        else
        {
            dp[i] = dp[i + 1];
        }
    }
    cout << *max_element(dp.begin() + 1, dp.end()) << "\n";
}