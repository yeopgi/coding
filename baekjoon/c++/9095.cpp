#include <cstdio>
#include <cstring>

#define ARRY_RANGE 11

int main(void)
{
    int d[ARRY_RANGE];
    int caseCnt = 0;
    scanf("%d", &caseCnt);

    while (caseCnt--)
    {
        memset(d, 0, sizeof(d));

        int testCnt = 0;
        scanf("%d", &testCnt);

        d[0] = 1;
        d[1] = 1;
        d[2] = 2;
        
        if(testCnt == 1)
        {   
            printf("1\n");
            continue;
        }

        if(testCnt == 2)
        {
            printf("2\n");
            continue;
        }
        
        for (int i = 3; i <= testCnt; i++)
        {
            d[i] = d[i - 1] + d[i - 2] + d[i - 3];
        }

        printf("%d\n", d[testCnt]);
    }

    return 0;
}
