#include <iostream>
#include <vector>

using namespace std;

int curveCnt;
int x, y, direct, generation;
int map[101][101];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
vector<int> directInfo;

void Drawing()
{
    int size = directInfo.size();
    for (int i = size - 1; i >= 0; i--) {
        int nextDirect = (directInfo[i] + 1) % 4;
        x = x + dx[nextDirect];
        y = y + dy[nextDirect];
        map[x][y] = 1;
        directInfo.push_back(nextDirect);
    }
}

void CheckSqure() 
{
    int squreCnt = 0;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1) {
                squreCnt++;
            }
        }
    }

    cout << squreCnt << '\n';
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> curveCnt;
    for (int i = 0; i < curveCnt; i++) {
        cin >> x >> y >> direct >> generation;
        directInfo.clear();

        directInfo.push_back(direct);
        
        map[x][y] = 1;
        x = x + dx[direct], y = y + dy[direct];
        map[x][y] = 1;
        for (int j = 0; j < generation; j++) {
            Drawing();
        }
    }

    CheckSqure();

    return 0;
}
