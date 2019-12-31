#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int kg, cnt;
    cin >> kg;
    cnt = kg / 5;
    if (kg % 5 != 0) {
        for (; cnt >= 0; cnt--) {
            if((kg - 5 * cnt) % 3 == 0) {
                cnt += (kg - 5 * cnt) / 3;
                break;
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}