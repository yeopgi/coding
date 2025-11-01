#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int table[5][5];
bool visited[5][5];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ans = 0;
int combinations[25] = {0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0,
                        0, 0, 0, 1, 1,
                        1, 1, 1, 1, 1};
bool test_Visited[5][5];
void Run(const int x, const int y, const int cnt, const vector<string> &strs)
{
    if (x > 4 || y > 4 || x < 0 || y < 0 || cnt > 7)
    {
        return;
    }
    if (visited[x][y])
    {
        return;
    }

    if (combinations[(x * 5) + (y % 5)] == 0)
    {
        return;
    }
    if (cnt == 7)
    {
        return;
    }
    visited[x][y] = true;
    test_Visited[x][y] = true;
    // cout << strs[x][y] << '\n';
    Run(x, y + 1, cnt + 1, strs);
    Run(x + 1, y, cnt + 1, strs);
    Run(x - 1, y, cnt + 1, strs);
    Run(x, y - 1, cnt + 1, strs);
    visited[x][y] = false;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> strs;
    for (int i = 0; i < 5; ++i)
    {
        string str;
        cin >> str;
        strs.push_back(str);
    }

    do
    {
        memset(visited, 0, sizeof(visited));
        memset(test_Visited, 0, sizeof(test_Visited));
        vector<pair<int, int>> candidates;
        int s_cnt = 0;
        for (size_t i = 0; i < 25; ++i)
        {
            if (combinations[i] == 1)
            {
                if (strs[i / 5][i % 5] == 'S')
                {
                    ++s_cnt;
                }
                candidates.push_back({i / 5, i % 5});
            }
        }

        // cout << candidates.size() << '\n';
        if (s_cnt < 4)
        {
            candidates.clear();
            continue;
        }
        Run(candidates[0].first, candidates[0].second, 0, strs);
        bool is_continuous = true;
        for (const auto i : candidates)
        {
            if (!test_Visited[i.first][i.second])
            {
                // cout << i.first << ' ' << i.second << '\n';
                is_continuous = false;
                break;
            }
        }

        if (is_continuous)
        {
            ++ans;
        }
    } while (next_permutation(combinations, combinations + 25));
    cout << ans << '\n';
    // cout << "ans : " << ans << '\n';
    return 0;
}