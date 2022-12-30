#include <iostream>
#include <algorithm>
using namespace std;

int d[100000 + 1];
int input[100000 + 1];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int inputNum;
    cin >> inputNum;
    for (int i = 1; i <= inputNum; i++) {
        cin >> input[i];
    }

    for (int i = 1; i <= inputNum; i++) {
        if (d[i - 1] + input[i] > input[i]) {
            d[i] = d[i - 1] + input[i];
        } else {
            d[i] = input[i];
        }
    }

    int max = d[1];
    for (int i = 2; i <= inputNum; i++) {
        if (max < d[i]) {
            max = d[i];
        }
    }

    cout << max;
    return 0;
}