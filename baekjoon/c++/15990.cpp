#include <cstdio>
#include <cstring>
using namespace std;

int main(void)
{   
    int d[100000 + 1][4];
    memset(d, 0, sizeof(d));

    d[0][0] = 0;
    d[0][1] = 0;
    d[0][2] = 0;
    d[0][3] = 0;
    d[1][1] = 1;
    d[1][2] = 0;
    d[1][3] = 0;
    d[2][1] = 0;
    d[2][2] = 1;
    d[2][3] = 0;
    d[3][1] = 1;
    d[3][2] = 1;
    d[3][3] = 1;
    int caseCnt = 0;
    scanf("%d", &caseCnt);
    
    while(caseCnt--)
    {
        int temp = 0;
        int num = 0;
        scanf("%d", &num);

        switch(num)
        {
            case 1:
                printf("1\n");
                continue;
            case 2:
                printf("1\n");
                continue;
            case 3:
                printf("3\n");
                continue;
            default:
                break;
        }

        for (int i = 4; i <= num; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                if (j == 1)
                {
                    d[i][j] = d[i - 1][3];
                    printf("%d haha1\n", d[i][j]);
                    temp += d[i][j];
                    continue;
                }
                if (j == 2)
                {
                    d[i][j] += d[i - 1][1];
                    printf("%d haha2\n", d[i][j]);
                    temp += d[i][j];
                    continue;
                }
                if (j == 3)
                {
                    d[i][j] += d[i - 1][2];
                    printf("%d haha3\n", d[i][j]);
                    temp += d[i][j];
                    break;
                }
            }
        }
        printf("%d\n", temp);
    }

    return 0;
}