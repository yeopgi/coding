#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> areaCnt;
bool visit[101][101];
int map[101][101];
int checkMap[101][101];
int isExist[101];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void Dfs(int x, int y) {
    if (visit[x][y]) {
        return;
    }

    visit[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int xTemp = x + dx[i];
        int yTemp = y + dy[i];
        if (xTemp >= 1 && xTemp <= N && yTemp >= 1 && yTemp <= N) {
            if (!visit[xTemp][yTemp]) {
                if (checkMap[xTemp][yTemp] == 0) {
                    Dfs(xTemp, yTemp);
                }
            }
        }
    }

}

void Run() {
    for (int i = 1; i <= 101; i++) {
        if (isExist[i] == 1) {
            for (int j = 1; j <= N; j++) {
                for (int k = 1; k <= N; k++) {
                    if (map[j][k] <= i) {
                        checkMap[j][k] = -1;
                    }
                }
            }

            int area = 0;
            for (int j = 1; j <= N; j++) {
                for (int k = 1; k <= N; k++) {
                    if (checkMap[j][k] == 0) {
                        Dfs(j, k);
                        area++;
                    }
                }
            }

            areaCnt.push_back(area);
            memset(checkMap, 0, sizeof(map));
            memset(visit, 0, sizeof(visit));
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
            if (isExist[map[i][j]] == 0) {
                isExist[map[i][j]] = 1;
            }
        }
    }

    Run();

    for (int i =0; i < areaCnt.size(); i++) {
        cout << areaCnt[i] << '\t';
    }
    cout << '\n';
    //cout << *max_element(areaCnt.begin(), areaCnt.end()) << '\n';
    return 0;
}