#include <deque>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int MAX = 100;
int N;
int dirCnt = 0;
int appleCnt = 0;
typedef struct
{
    int x;
    int y;
} Dir;

Dir dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool apple[MAX][MAX];
bool leaves[MAX][MAX];
deque<pair<int, char>> direct; // <time, direction>
int today;

int Run(int startX, int startY)
{
    deque<pair<int, int>> snake;
    snake.push_front({startX, startY}); // push -> push_front, pop -> pop_back
    leaves[startX][startY] = true;
    int idx = 0;
    int currentX = startX, currentY = startY;
    while (1) {
        today++;
        currentX = currentX + dir[idx].x;
        currentY = currentY + dir[idx].y;
        if (leaves[currentX][currentY] || !(currentX >= 0 && currentX < N && currentY >= 0 && currentY < N)) { // 2. 자기자신과 부딪혀 종료
            return today;
        }

        leaves[currentX][currentY] = true;
        snake.push_front({currentX, currentY});
        if (apple[currentX][currentY]) {
            apple[currentX][currentY] = false;
        } else {
            leaves[snake.back().first][snake.back().second] = false;
            snake.pop_back();
        }

        if (direct.size() > 0 && today == direct.front().first) {
            if (direct.front().second == 'L') {
                idx = (idx + 3) % 4; 
            } else {
                idx = (idx + 1) % 4;
            }

            direct.pop_front();
        } 
    }

    return today;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cin >> appleCnt;
    for (int i = 0; i < appleCnt; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        apple[temp1 - 1][temp2 - 1] = true;
    }

    cin >> dirCnt;
    for (int i = 0; i < dirCnt; i++) {
        int temp1;
        char temp2;
        cin >> temp1 >> temp2;
        direct.push_back({temp1, temp2});
    }

    today = 0;
    cout << Run(0, 0) << '\n';
    return 0;
}