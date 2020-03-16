#include <iostream>
#include <cstring>
using namespace std;

typedef struct informationTP
{
    int t, p;
}informationTP;

informationTP tp[16];
int d[16][121];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int limitDay;
    cin >> limitDay;
    for (int i = 1; i <= limitDay; i++) {
        cin >> tp[i].t >> tp[i].t;
    }

    for (int startDay = 2; startDay <= limitDay; startDay++) {
        
    }

    return 0;
}