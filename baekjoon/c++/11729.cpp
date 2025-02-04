#include <iostream>
using namespace std;

void Run(const int a, const int b, const int n) {
    if (1 == n) {
        cout << a << ' ' << b << '\n';
        return;
    }

    Run(a, 6 - a - b, n - 1);
    cout << a << ' ' << b << '\n';
    Run(6 - a - b, b, n - 1);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    cout << (1 << k) - 1 << '\n';
    Run(1, 3, k);
}