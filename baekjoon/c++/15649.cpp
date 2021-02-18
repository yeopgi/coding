#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N, M;
int a[9];
int cache[9];
vector<int> v;

void Run(int start, int next, int recursiveCnt)
{
    if (recursiveCnt == M - 1) {
        cout << start << ' ';
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << ' ';
        }

        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (start != i) {
            v.emplace_back(i);
            Run(start, i, recursiveCnt + 1);
            v.pop_back();
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        a[i] = i;
    }

    if (M == 1) {
        for (int i = 1; i <= N; i++) {
            cout << i << '\n';
        }

        return 0;
    }

    for (int i = 1; i <= N; i++) {
        memset(cache, -1, sizeof(cache));

        Run(i, 0, 0);

        v.clear();
    }

    return 0;
}