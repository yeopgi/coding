#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};
bool visit[101][101];
vector<vector<int>> map;
int M, N, H;
queue<pair<pair<int, int>, int>> q;

void Bfs(int i, int j)
{

}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N >> H;
    map.resize(N);
    for (int i = 0; i < N; i++) {
        map[i].resize(M);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visit[i][j] && map[i][j] == 1) {
                Bfs(i, j);
            }
        }
    }
    /*vector<vector<int>> copyMap(H);
    for (int i = 0; i < H; i++) {
        copyMap[i] = map[i];
    }*/





    return 0;
}