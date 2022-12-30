#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int map[31][31][31];
bool visit[31][31][31];
int L, R, C;
pair<pair<int, int>, int> start;
pair<pair<int, int>, int> terminal;
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int Bfs(int a, int b, int c) {
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push(make_pair(make_pair(a, b), make_pair(c, 0)));
    visit[a][b][c] = true;
    while (!q.empty()) {
        int z = q.front().first.first;
        int x = q.front().first.second;
        int y = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();

        if (z == terminal.first.first && x == terminal.first.second && y == terminal.second) {
            return cnt;
        }

        for (int i = 0; i < 6; i++) {
            int nz = z + dz[i];
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nz >= 1 && nx >= 1 && ny >= 1 && nz <= L && nx <= R && ny <= C) {
                if (map[nz][nx][ny] == '#') {
                    continue;
                }
        
                if (map[nz][nx][ny] == '.' || map[nz][nx][ny] == 'E') {
                    if (!visit[nz][nx][ny]) {
                        visit[nz][nx][ny] = true;
                        q.push(make_pair(make_pair(nz, nx), make_pair(ny, cnt + 1)));
                    }
                }
            }
        }
    }

    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0) {
            break;
        }

        for (int i = 1; i <= L; i++) {
            for (int j = 1; j <= R; j++) {
                for (int k = 1; k <= C; k++) {
                    cin >> map[i][j][k];
                    if (map[i][j][k] == 'S') {
                        start.first.first = i;
                        start.first.second = j;
                        start.second = k;
                    } else if (map[i][j][k] == 'E') {
                        terminal.first.first = i;
                        terminal.first.second = j;
                        terminal.second = k;
                    }
                }
            }
        }

        int r = Bfs(start.first.first, start.first.second, start.second);
        if (r == -1) {
            cout << "Trapped!" << '\n';
        } else {
            cout << "Escaped in " << r << " minute(s)." << '\n';
        }

        memset(visit, false, sizeof(visit));
    }

    return 0;
}