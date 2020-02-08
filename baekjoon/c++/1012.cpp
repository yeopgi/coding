#include <iostream>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int row, col, cabbage;
int where[50][50];
bool visit[50][50];
int cnt;

void Dfs(int xStart, int yStart) {
    visit[xStart][yStart] = true;
    cout << "xStart : " << xStart << ' ' << "yStart : " << yStart << endl;
    for (int i = 0; i < 4; i++) {
        int xTemp = xStart + dx[i];
        //cout << "xTemp : " << xTemp << endl;
        int yTemp = yStart + dy[i];
        //cout << "yTemp : " << yTemp << endl;
        if (xTemp >= 0 && yTemp >= 0 && xTemp < col && yTemp < row) {
            if (!visit[yTemp][xTemp] && where[yTemp][xTemp] == 1) {
                //cout << "진입" << endl;
                Dfs(yTemp, xTemp);
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
        cnt = 0;
        cin >> col >> row >> cabbage;
        while (cabbage--) {
            int xTemp, yTemp;
            cin >> xTemp >> yTemp;        
            where[yTemp][xTemp] = 1;
        }

        cout << cnt << '\n';
        for(int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!visit[i][j] && where[i][j] == 1) {
                    Dfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
        fill_n(&where[0][0], &where[row -1][col], 0);
        fill_n(&visit[0][0], &visit[row - 1][col], -1);
    }

    return 0;
}