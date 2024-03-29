#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool check[30][30];
int n, arr[30][30],num[1010],cnt;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
 
void dfs(int x,int y) {
    check[x][y] = true;
    num[cnt]++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
            if (!check[nx][ny] &&arr[nx][ny]) dfs(nx, ny);
        }
    }
}
int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %1d", &arr[i][j]);
        }
    }
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!check[i][j] && arr[i][j]) dfs(i, j), cnt++;
        }
    }
    printf("%d\n", cnt);
    sort(num, num + cnt);
    for (int i = 0; i < cnt; i++) printf("%d\n", num[i]);
}

//출처 : https://sejinik.tistory.com/59