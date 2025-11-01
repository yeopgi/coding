#include <iostream>
using namespace std;

#define ll long long

ll Run(const ll a, const ll b, const ll c) {
    if (1 == b) {
        return a % c;
    }

    ll temp = Run(a, b / 2, c);
    ll val = temp * temp % c;
    if ((b % 2) != 0)    {
        return val * (a % c) % c;
    } else {
        return val;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // ll a = 12, b = 116, c = 67;
    ll a, b, c;
    cin >> a >> b >> c;
    cout << Run(a, b, c) << '\n';
}