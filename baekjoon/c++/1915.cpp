#include <iostream>
#include <string>
using namespace std;

const int MAX = 1000;
int n, m;
string map[MAX];
int d[MAX][MAX];

int Run()
{
    int maxNum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0)
            {
                d[i][j] = map[i][j] - '0';
            }
            else if (map[i][j] == '1')
            {
                d[i][j] = min(min(d[i - 1][j - 1], d[i - 1][j]), d[i][j - 1]) + 1;
            }

            maxNum = max(maxNum, d[i][j]);
        }
    }

    return maxNum;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m; // n행 m열
    for (int i = 0; i < n; i++)
    {
        cin >> map[i];
    }

    int ans = Run();
    cout << ans * ans << '\n';
    return 0;
}