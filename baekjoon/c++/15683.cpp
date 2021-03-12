#include <iostream>
#include <vector>
using namespace std;

typedef struct Dir {
    int x, y;
} Dir;

Dir dir[4] = {
    {0, 1},
    {-1, 0},
    {0, -1},
    {1, 0}};

int N, M;
const int MAX = 8;
int a[MAX + 1][MAX + 1];
vector<pair<int, int>> cam;
vector<int> angle;
bool isFacing[MAX + 1][MAX + 1][4];
int res = 987654321;
int copyMap[MAX + 1][MAX + 1];

int BlindLocationCnt()
{
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (copyMap[i][j] == 0) {
                cnt++;
            }
        }
    }

    return cnt;
}

void CopyMapInit()
{
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            copyMap[i][j] = a[i][j];
        }
    }
}


void Run(int cnt)
{
    if (cnt == cam.size()) {
        for (int i = 0; i < angle.size(); i++) {
            int x = cam[i].first;
            int y = cam[i].second;
            for (int j = 0; j < 4; j++) { // 어느 종류의 카메라인지 확인
                if (isFacing[x][y][j]) {
                    int nx = dir[(angle[i] + j) % 4].x + x;
                    int ny = dir[(angle[i] + j) % 4].y + y;
                    while (1) {
                        if (nx < 1 || nx > N || ny < 1 || ny > M) {
                            break;
                        }

                        if (copyMap[nx][ny] == 6) {
                            break;
                        }

                        copyMap[nx][ny] = '#';
                        nx = nx + dir[(angle[i] + j) % 4].x;
                        ny = ny + dir[(angle[i] + j) % 4].y;
                    }
                }
            }
        }

        res = min(BlindLocationCnt(), res);
        CopyMapInit();

        return;
    }

    for (int i = 0; i < 4; i++) {
        angle.push_back(i);
        Run(cnt + 1);
        angle.pop_back();
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                isFacing[i][j][0] = true;
                cam.push_back({i, j});
                continue;
            }

            if (a[i][j] == 2) {
                isFacing[i][j][0] = true;
                isFacing[i][j][2] = true;
                cam.push_back({i, j});
                continue;
            }

            if (a[i][j] == 3) {
                isFacing[i][j][0] = true;
                isFacing[i][j][1] = true;
                cam.push_back({i, j});
                continue;
            }

            if (a[i][j] == 4) {
                isFacing[i][j][0] = true;
                isFacing[i][j][2] = true;
                isFacing[i][j][1] = true;
                cam.push_back({i, j});
                continue;
            }

            if (a[i][j] == 5) {
                isFacing[i][j][0] = true;
                isFacing[i][j][2] = true;
                isFacing[i][j][1] = true;
                isFacing[i][j][3] = true;
                cam.push_back({i, j});
                continue;
            }
        }
    }

    CopyMapInit();

    Run(0);

    cout << res << '\n';
    return 0;
}