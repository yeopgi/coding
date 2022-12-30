#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int map[1001][1001];
int col, row;
int noTomato = 0;
queue<pair<int, int>> ripeIdx;

int Bfs() {
    int day = 0;
    int ripeCnt = 0;
    while (!ripeIdx.empty()) {
        int queueSize = ripeIdx.size();
        ripeCnt += queueSize;
        while (queueSize--) {
            for (int i = 0; i < 4; i++) {
                int xTemp = ripeIdx.front().first + dx[i];
                int yTemp = ripeIdx.front().second + dy[i];

                if (xTemp > 0 && xTemp <= row && yTemp > 0 && yTemp <= col) {
                    if (map[xTemp][yTemp] == 0) {
                        ripeIdx.push(make_pair(xTemp, yTemp));
                        map[xTemp][yTemp] = 1;
                    }
                }
            }

            ripeIdx.pop();
        }
        
        day++;
    }

    if (ripeCnt == col * row - noTomato) {
        return day - 1;
    } else {
        return -1;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> col >> row;
    int ripeCnt = 0;
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                ripeIdx.push(make_pair(i, j));
                ripeCnt++;
            } else if (map[i][j] == -1) {
                noTomato++;
            }
        }
    }

    if (ripeCnt == col * row - noTomato) {
        cout << 0 << '\n';
        return 0;
    } 

    int answer = Bfs();
    cout << answer << '\n';
    return 0;
}