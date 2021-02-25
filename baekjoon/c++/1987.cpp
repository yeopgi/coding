#include <iostream>
#include <cstring>
#include <string>
#include <unordered_map>
using namespace std;

int R, C;
const int MAX = 20;
int a[MAX + 1][MAX + 1];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visit[MAX + 1][MAX + 1];
string str[MAX + 1];
unordered_map<char, int> um1, um2;
int answer;

int Run(int srcX, int srcY)
{
    if (visit[srcX][srcY]) {
        return 0;
    }

    visit[srcX][srcY] = true;
    int cnt = 1;
    for (int i = 0; i < 4; i++) {
        int nx = srcX + dx[i];
        int ny = srcY + dy[i];
        if (nx >= 1 && nx <= R && ny >= 1 && ny <= C) {
            if (!visit[nx][ny]) {
                if (um1[a[nx][ny]] == um2[a[nx][ny]]) {
                    um1[a[nx][ny]]--;
                    cnt += Run(nx, ny);
                }
            }
        }
    }

    return cnt;
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    answer = 0;
    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        cin >> str[i];
        for (int j = 1; j <= C; j++) {
            a[i][j] = str[i][j];
            um1[a[i][j]]++;
        }
    }

    um2 = um1;
    answer = Run(1, 1);
    cout << answer + 1 << '\n';
    return 0;
}