#include <cstdio>

int main(void)
{
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            putchar('*');
        }
     
        putchar('\n');
    }

    return 0;
}