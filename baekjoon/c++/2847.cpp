#include <iostream>
#include <array>

using namespace std;
int N;
int tot = 0;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    array<int, 100 + 1> arr = {0};
    for (size_t i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    for (size_t i = N; i >= 1; --i)
    {
        for (size_t j = i - 1; j >= 1; --j)
        {
            if (arr[j] >= arr[i])
            {
                const int minus_cnt = arr[j] - arr[i] + 1;
                // cout << "minus_cnt : " << minus_cnt << ", i : " << i << ", j : " << j << endl;
                // cout << "arr[j] : " << arr[j] << ", arr[i] : " << arr[i] << endl;
                tot += minus_cnt;
                arr[j] -= minus_cnt;
            }
        }
    }
    cout << tot << '\n';
}