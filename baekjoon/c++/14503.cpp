#include <iostream>
#include <array>
#include <queue>
using namespace std;

typedef struct Dir
{
    int x;
    int y;
    Dir(int _x, int _y) : x(_x), y(_y) {};
} Dir;

Dir dir[4] = {
    {-1, 0}, // 0 : 북
    {0, 1}, // 1 : 동
    {1, 0}, // 2 : 남
    {0, -1} // 3 : 서
};
int N, M;
const int MAX = 50 + 1;
int a[MAX][MAX];

void Run(Dir _currentLocation, int _currentDir)
{
    if (a[_currentLocation.x][_currentLocation.y] == 1) {
        return;
    }

    a[_currentLocation.x][_currentLocation.y] = -1;     // 현재 공간 청소해주고
    int tempDir = (_currentDir + 3) % 4;                //  한 번 왼쪽으로 방향 틀어본다.
    int x = _currentLocation.x + dir[tempDir].x,
        y = _currentLocation.y + dir[tempDir].y;
    //cout << _currentLocation.x << ' ' << _currentLocation.y << '\n';
    if (a[x][y] == 0) {                         // 왼쪽으로 튼 방향에 청소하지않은 공간이 있다면
        Run(Dir(x, y) , tempDir);               // 그 방향으로 회전한 다음 한 칸 전진
    } else {                                    // 왼쪽으로 튼 방향에 청소할 공간이 없다면
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            int _x = _currentLocation.x + dir[i].x;
            int _y = _currentLocation.y + dir[i].y;
            if (a[_x][_y] == -1 || a[_x][_y] == 1) {
                cnt++;
            }
        }

        if (cnt == 4) {                     // 네 방향 모두 청소가 되어있거나, 벽인 경우
            int _x = _currentLocation.x - dir[_currentDir].x;
            int _y = _currentLocation.y - dir[_currentDir].y;
            Run(Dir(_x, _y), _currentDir);
        } else {
            _currentDir = tempDir;
            Run(_currentLocation, _currentDir);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    Dir currentLocation(0, 0);
    int currentDir; // 0 : 북, 1 : 동, 2 : 남, 3 : 서
    cin >> currentLocation.x >> currentLocation.y >> currentDir;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    Run(currentLocation, currentDir);

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == -1) {
                ans++;
            }
            //cout << a[i][j] << ' ';
        }

        //cout << '\n';
    }

    cout << ans << '\n';
    return 0;
}