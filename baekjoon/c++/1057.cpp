#include <iostream>
using namespace std;

int N;
int jimin;
int hansu;

int Run()
{
    int round = 1;
    if ((jimin + 1) / 2 == (hansu + 1) / 2) {
        return round;
    }

    while (N) {
        jimin = (jimin + 1) / 2;
        hansu = (hansu + 1) / 2;
        N = N / 2;
        ++round;
        if ((jimin + 1) / 2 == (hansu + 1) / 2) {
            return round;
        }
    }

    return 0;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> jimin >> hansu;
    int round = Run();
    cout << round << '\n';
    return 0;
}