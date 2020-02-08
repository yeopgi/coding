#include <iostream>
#include <cstring>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int row, col, cabbage;
int where[50][50];
bool visit[50][50];

void Dfs(int xStart, int yStart) {
    visit[xStart][yStart] = true;
    //cout << "xStart : " << xStart << ' ' << "yStart : " << yStart << endl;
    for (int i = 0; i < 4; i++) {
        int xTemp = xStart + dx[i];
        int yTemp = yStart + dy[i];
        if (xTemp >= 0 && yTemp >= 0 && xTemp < row && yTemp < col) {
            if (!visit[xTemp][yTemp] && where[xTemp][yTemp] == 1) {
                Dfs(xTemp, yTemp);
            }
        }
    }
}

int main(void)
{   
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test;
    cin >> test;
    while (test--) {
        memset(where, 0, sizeof(where));
        memset(visit, false, sizeof(visit));
        int cnt = 0;
        cin >> col >> row >> cabbage;
        while (cabbage--) {
            int xTemp, yTemp;
            cin >> xTemp >> yTemp;        
            where[yTemp][xTemp] = 1;
        }

        for(int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!visit[i][j] && where[i][j] == 1) {
                    Dfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}