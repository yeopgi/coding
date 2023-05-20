#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int         N, M;
vector<int> my_vector;
int         ans[10000 + 1];

void Run(const int start_idx, const int depth) {
    ans[depth] = my_vector[start_idx];
    if (depth == M - 1) {
        for (int i = 0; i < M; i++) {
            cout << ans[i] << ' ';
        }

        cout << '\n';
        return;
    }

    for (int i = 1; i < my_vector.size(); i++) {
        Run(i, depth + 1);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    my_vector.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> my_vector[i];
    }

    sort(my_vector.begin(), my_vector.end());

    if (M == 1) {
        for (int i = 1; i <= N; i++) {
            cout << my_vector[i] << '\n';
        }

        return 0;
    }

    cout << '\n';
    for (int i = 1; i <= N; i++) {
        Run(i, 0);
    }
}