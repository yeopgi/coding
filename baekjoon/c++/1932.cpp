<<<<<<< HEAD
#include <iostream>
using namespace std;

int d[501][501];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, sum = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; i++) {
            cin >> d[i][j];
        }
    }

    

    return 0;
}
=======
#include <stdio.h>
int Max(int a, int b) { return a > b ? a : b; }

int main() {
    int i, j, n, max = 0, d[501][501] = {0};
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= i; j++) {
            scanf("%d", &d[i][j]);
            if (j == 1)
                d[i][j] = d[i - 1][j] + d[i][j];
            else if (j == i)
                d[i][j] = d[i - 1][j - 1] + d[i][j];
            else
                d[i][j] = Max(d[i - 1][j - 1], d[i - 1][j]) + d[i][j];
            if (max < d[i][j])
                max = d[i][j];
        }
    printf("%d", max);
    
    return 0;
}

//출처 : https://blog.naver.com/occidere/220789773974
>>>>>>> b24fca794516c0210d9885c8476e3cffd4833676
