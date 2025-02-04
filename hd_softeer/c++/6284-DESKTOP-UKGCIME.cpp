#include<iostream>


using namespace std;

long long nums[1000000 + 2];
constexpr long long mod_num = 1000000007;
int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

    int k, p, n;
    cin >> k >> p >> n;
    nums[0] = k %mod_num;
    long long res = nums[0];
    for (size_t i = 1; i <= n ; ++i) {
        nums[i] = p % mod_num;
        res *= nums[i];
    }

    cout << res << '\n';
    
   return 0;
}