#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int MAX = 100;
char a[MAX];
char z[MAX];
int cnt = 1;
unordered_map<int, string> um;
int N, M, K;    

void Run(const int aIdx, const int zIdx, const int aCnt, const int zCnt, string current)
{
    if (current.length() == N + M) {
        um[cnt++] = current;
        return;
    }
    
    for (int i = aIdx + 1; i < N; i++) {
        Run(i, zIdx, aCnt + 1, zCnt, current + a[i]);
    }

    for (int i = zIdx + 1; i < M; i++) {
        Run(aIdx, i, aCnt, zCnt + 1, current + z[i]);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        a[i] = 'a';
    }

    for (int i = 0; i < M; i++) {
        z[i] = 'z';
    }

    Run(-1, -1, 0, 0, "");

    if (um.size() < K) {
        cout << -1 << '\n';
        return 0;
    }

    cout << um[K] << '\n';
    return 0;   
}