#include <iostream>
using namespace std;

int N;
int is_used1[40] = {0};
int is_used2[40] = {0};
int is_used3[40] = {0};
int ans = 0;
void Run(const int cnt) {
    if (N == cnt) {
        ans++;
        return;
    }

    for (size_t i = 0; i < N; ++i) {
        if (is_used1[i] || is_used2[cnt + i] || is_used3[cnt - i + N - 1]) {
            continue;
            ;
        }
        is_used1[i] = 1;
        is_used2[cnt + i] = 1;
        is_used3[cnt - i + N - 1] = 1;
        Run(cnt + 1);

        is_used1[i] = 0;
        is_used2[cnt + i] = 0;
        is_used3[cnt - i + N - 1] = 0;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;

    Run(0);
    cout << ans << '\n';
}