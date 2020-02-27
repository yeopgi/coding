 #include <iostr>
#include <vector>
using namespace std;

vector<vector<int>> v;
bool visit[101];
int virus = 0;

void check(int start)
{
    virus++;
    visit[start] = true;
    for (int i = 0; i <v[start].size(); i++) {
        if (!visit[v[start][i]]) {
            check(v[start][i]);
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
        v[from].push_back(to);
        v[to].push_back(from);
    }

    check(1);

    cout << virus - 1;
    return 0;
}
