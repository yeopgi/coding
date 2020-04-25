#include <iostream>
#include <vector>
#include <string>
using namespace std;

int col, row;
int prev;
vector<string> v;
vector<pair<int, int>> red;
vector<pair<int, int>> blue;
vector<pair<int, int>> hole;
int map[11][11];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visit[11][11];
bool isSameTime;


void Explore(pair<int, int> start) {
    if (!visit[start.first][start.second]) {
        return;
    }

    visit[start.first][start.second] = true;
    for (int i = 0; i < 4; i++) {
        int xTemp = start.first + dx[i];
        int yTemp = start.second + dy[i];
        if (xTemp >= 1 && xTemp <= row && yTemp >= 1 && yTemp <= col && !visit[xTemp][yTemp]) {
            Explore({xTemp, yTemp});
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> col >> row;
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'B') {
                blue.push_back({i,j});
                continue;
            } 

            if (map[i][j] == 'R') {
                red.push_back({i,j});
                continue;
            }
        
            if (map[i][j] == 'O') {
                hole.push_back({i,j});
            }
        }
    }    





    return 0;
}