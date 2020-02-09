//카드 구매하기 2
#include <iostream>
using namespace std;

int main(void)
{
    int d[10000 + 1] = {0};
    int price[10000 + 1] = {0};

    int range;
    cin >> range;
    price[0] = 0;
    for (int i = 1; i <= range; i++)
    {
        cin >> price[i];
    }

    if(range == 1) 
    {
        cout << price[1] << '\n';
        return 0;
    }

    d[0] = 0;
    d[1] = price[1];
    d[2] = min(price[2], price[1] + d[1]);      // 2장까지의 최솟값

    for(int i = 2; i <= range; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            if(d[i] == 0)
            {
                d[i] = price[j] + d[i - j];
                continue;
            }
            d[i] = min(price[j] + d[i - j], d[i]);
        }
    }

    cout << d[range] << '\n';
    return 0;
}

int min(int src1, int src2)
{
    return src1 > src2 ? src2 : src1;
}