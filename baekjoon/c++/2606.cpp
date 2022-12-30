 #include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map;
bool visit[101];
int virus = 0;

void check(int start)
{
    virus++;
    visit[start] = true;
    for (int i = 0; i <map[start].size(); i++) {
        if (!visit[map[start][i]]) {
            check(map[start][i]);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int computer, connection;

   cin >> computer >> connection;
    map.resize(computer + 1);
    while (connection--) {
        int from, to;
        cin >> from >> to;
        map[from].push_back(to);
        map[to].push_back(from);
    }

    check(1);

    cout << virus - 1;
    return 0;
}
