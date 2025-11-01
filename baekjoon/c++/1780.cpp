#include <iostream>
#include <array>
using namespace std;
array<int, 3> cnt = {0, 0, 0};
std::array<std::array<int, 2187 + 1>, 2187 + 1> nums;

void Run(const int x, const int y, const int depth)
{
    bool all_same = true;
    for (size_t i = x; i < x + depth; i++)
    {
        for (size_t j = y; j < y + depth; j++)
        {
            if (nums[x][y] != nums[i][j])
            {
                all_same = false;
            }
        }
    }

    if (all_same)
    {
        if (nums[x][y] == -1)
            cnt[0]++;
        else if (nums[x][y] == 0)
            cnt[1]++;
        else if (nums[x][y] == 1)
            cnt[2]++;
    }
    else
    {
        Run(x, y, depth / 3);
        Run(x, y + (1 * (depth / 3)), depth / 3);
        Run(x, y + (2 * (depth / 3)), depth / 3);
        Run(x + (1 * (depth / 3)), y, depth / 3);
        Run(x + (1 * (depth / 3)), y + (1 * (depth / 3)), depth / 3);
        Run(x + (1 * (depth / 3)), y + (2 * (depth / 3)), depth / 3);

        Run(x + (2 * (depth / 3)), y, depth / 3);
        Run(x + (2 * (depth / 3)), y + (1 * (depth / 3)), depth / 3);
        Run(x + (2 * (depth / 3)), y + (2 * (depth / 3)), depth / 3);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cin >> nums[i][j];
        }
    }

    Run(0, 0, N);
    for (auto &i : cnt)
    {
        cout << i << '\n';
    }
}