#include <cstring>
#include <vector>

using namespace std;

int visit[200];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int except = 0;

void Dfs(int src, vector<vector<int>> &v)
{
    if (!visit[src]) {
        return;
    }

    visit[src] = true;
    for (size_t i = 0; i < v[src].size(); i++) {
        Dfs(v[src][i], v);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    memset(visit, 0, sizeof(visit));
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }

            if (computers[i][j] == 1) {
                v[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (visit[i]) {
            continue;
        }
        
        visit[i] = true;
        size_t j;
        for (j = 0; j < v[i].size(); j++) {
            Dfs(v[i][j], v);
            answer++;
        }

        if (j == 0) {
            except++;
        }
    }

    answer += except;
    return answer;
}