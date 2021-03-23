#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int maxNum = 0;
    do {
        int result = 0;
        for (int i = 0; i < N - 1; i++) {
            result += abs(v[i] - v[i + 1]);
            maxNum = max(result, maxNum);
        }
    } while (next_permutation(v.begin(), v.end()));

    cout << maxNum << '\n';
    return 0;
}