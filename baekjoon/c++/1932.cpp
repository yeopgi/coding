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
