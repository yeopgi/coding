#include <iostream>
using namespace std;

int d[31];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int length;
    cin >> length;
    if (length % 2 == 0) {
        for (int i = 4; i <= length; i += 2) {
            d[i] = d[i - 2] * 3;
            for (int j = 4; i - j >= 0; j += 2) {
                d[i] = d[i - j] * 2;
            }
        }
    }

    cout << d[length] << endl;
    return 0;
}