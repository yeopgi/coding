#include <algorithm>
#include <iostream>
using namespace std;

int d[101][100001];
int weight[101], value[101];

int main() 
{
    int cnt, maxWeight, answer;
    cin >> cnt >> maxWeight;
    for (int i = 1; i <= cnt; i++) {
        cin >> weight[i] >> value[i];
    }

    for (int i = 1; i <= cnt; i++) {
        for (int j = 0; j <= maxWeight; j++) {
            if (j - weight[i] >= 0) {
                d[i][j] = max(d[i][j], d[i - 1][j - weight[i]] + value[i]);
            }
            
            d[i][j] = max(d[i][j], d[i - 1][j]);
        }

    }

    cout << d[cnt][maxWeight] << '\n';
}
