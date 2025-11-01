#include <iostream>
#include <array>
using namespace std;

int N;
array<pair<int, int>, 1500000 + 1> nums;
array<int, 1500000 + 1> dp = {-1};
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
    dp[1]=nums[1].second; // Profit
    for (int i = 2; i <= N; i++)
    {
        if (nums[i].first + (i -1) + 1 < N) {
            dp[i] = nums[i].second + dp[i-1];
        } else if (nums[i-1].first + (i -1) + 1 >= N) {
            
        }
            
            
        else
        dp[i] = max(dp[i - 1], nums[i].second);
    }
}