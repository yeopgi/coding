#include <iostream>
#include <cstring>
using namespace std;

int map[101][101];
bool visit[101];
int N;

void Dfs(int from) {
    for (int i = 1; i <= N; i++) {
        if (map[from][i] == 1) {
            if (!visit[i]) {
                visit[i] = true;
                Dfs(i);
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        memset(visit, false, sizeof(visit));

        Dfs(i);

        for (int j = 1; j <= N; j++) {
            if (visit[j]) {
                map[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << map[i][j] << ' ';
        }

        cout << '\n';
    }

    return 0;
}