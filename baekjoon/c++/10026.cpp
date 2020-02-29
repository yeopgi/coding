#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

char map[101][101];
bool visit[101][101];
vector<pair<int, int>> greenIdx;
char colorList[3] = {'R', 'B', 'G'};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int nonBlind = 0, blind = 0;
int range;

void Check(pair<int, int> start, char color) 
{
    int x = start.first, y = start.second;
    visit[x][y] = true;
    for (int j = 0; j < 4; j++) {
        int xTemp = x + dx[j];
        int yTemp = y + dy[j];
        if (!visit[xTemp][yTemp] && map[xTemp][yTemp] == color && xTemp >= 1 && yTemp >= 1 && xTemp <= range && yTemp <= range) {
            Check(make_pair(xTemp, yTemp), color);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> range;
    for (int i = 1; i <= range; i++) {
        for (int j = 1; j <= range; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= range; j++) {
            for (int k = 1; k <= range; k++) {
                if (map[j][k] == 'G') {
                    greenIdx.push_back(make_pair(j, k));
                }

                if (!visit[j][k] && map[j][k] == colorList[i]) {
                    Check(make_pair(j, k), colorList[i]);
                    nonBlind++;
                }
            }
        }
    }

    for (int i = 0; i < greenIdx.size(); i++) {
        int x = greenIdx[i].first, y = greenIdx[i].second;
        map[x][y] = 'R';
    }

    memset(visit, false, sizeof(visit));

    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= range; j++) {
            for (int k = 1; k <= range; k++) {
                if (!visit[j][k] && map[j][k] == colorList[i]) {
                    Check(make_pair(j, k), colorList[i]);
                    blind++;
                }
            }
        }
    }

    cout << nonBlind << ' ' << blind << '\n';
    return 0;
}
