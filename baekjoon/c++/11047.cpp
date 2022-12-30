#include <iostream>
#include <string>
using namespace std;

int coin[10 + 1];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int kind, total;
    cin >> kind >> total;
    for (int i = 1; i <= kind; i++) {
        cin >> coin[i];
    }

    int sum = 0, cnt = 0;
    for (int i = kind; i >= 1; i--) {
        while (sum < total) {
            sum += coin[i];
            cnt++;
        }

        if (sum == total) {
            cout << cnt;
            return 0;
        } else {
            sum -= coin[i];
            cnt--;
        }
    }

    return 0;
}