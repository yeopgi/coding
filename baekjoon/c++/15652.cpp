#include <iostream>
using namespace std;

const int MAX = 8 + 1;
int N, M;
int a[MAX];

void Run(int cnt)
{
    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << a[i] << ' ';
        }

        cout << '\n';
        return;
    }

    for (int i = (cnt == 0) ? 1 : a[cnt - 1]; i <= N; i++) {
        a[cnt] = i;
        Run(cnt + 1);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    Run(0);

    return 0;
}