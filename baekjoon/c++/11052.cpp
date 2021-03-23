//카드 구매하기
#include <iostream>
using namespace std;

int d[10000 + 1];
int price[10000 + 1];

int max(int, int);

int main(void)
{
    int temp;
    cin >> temp;
    price[0] = 0;
    for (int i = 1; i <= temp; i++)
    {
        cin >> price[i];
    }

    if(temp == 1) 
    {
        cout << price[1] << '\n';
        return 0;
    }

    d[0] = 0;
    d[1] = price[1];
    for (int i = 2; i <= temp; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            d[i] = max(price[j] + d[i - j], d[i]);
        }
    }

    cout << d[temp] << '\n';
    return 0;
}

int max(int src1, int src2)
{
    return src1 > src2 ? src1 : src2;
}