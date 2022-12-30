#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

bool visit[200];

void Dfs(int src, vector<vector<int>> &v)
{
    if (visit[src]) {
        return;
    }

    visit[src] = true;
    for (size_t i = 0; i < v[src].size(); i++) {
        Dfs(v[src][i], v);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int except = 0;
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
        for (size_t j = 0; j < v[i].size(); j++) {
            Dfs(v[i][j], v);
            answer++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (v[i].size() == 0) {
            except++;
        }
    }

    answer += except;
    return answer;
}