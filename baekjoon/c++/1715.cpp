#include <iostream>
#include <queue>
using namespace std;

int N;
int a[100001];

int Run()
{
    priority_queue<int> pq;
    for (int i = 1; i <= N; i++) {
        pq.push(-a[i]);
    }

    int total = 0;
    int cnt = 0;
    while (!pq.empty()) {
        cnt++;
        int _first = -pq.top();
        pq.pop();
        int _second = -pq.top();
        pq.pop();
        total += _first + _second;
        if (cnt == N - 1) {
            break;
        }

        pq.emplace(-(_first + _second));
    }

    return total;
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    if (N == 1) {
        cout << 0 << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    cout << Run() << '\n';
    return 0;
}