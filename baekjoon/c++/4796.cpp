#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int i = 1;
    while (true) {
        long long L, P, V;
        cin >> L >> P >> V;
        if (L * P * V == 0)
            break;

        long long mod = V % P;
        long long package = V / P;
        if (mod > L)
            mod = L;

        long long ans = ((L) * package) + mod;
        cout << "Case " << i++ << ": " << ans << '\n';
    }

    return 0;
}