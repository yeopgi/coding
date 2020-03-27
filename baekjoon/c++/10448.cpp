#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test;
    cin >> test;
    while (test--) {
        int k, cnt = 0;
        cin >> k;
        int init = k;
        for (int i = 1;; i++) {
            if (k <= (i * (i + 1)) / 2) {
                if (k == (i * (i + 1)) / 2) {
                    if (k - ((i * (i + 1)) / 2) == 0 && cnt + 1 == 3) {
                        cout << 1 << '\n';
                    }
                }

                int temp = i - 1;
                k -= (temp * (temp + 1)) / 2;
                cnt++;
                i = 1;
                if (k == 0) {
                    if (cnt == 3) {
                        cout << 1 << '\n';
                        break;
                    } else {
                        cout << 0 << '\n';
                        break;
                    }
                } else if (k < 0) {
                    cout << 0 << '\n';
                    break;
                }
            }
        }
    }

    return 0;
}