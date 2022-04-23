#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<long long> rope;

long long maxWeight(void)
{
    long long result = 0;
    //각각의 로프는 한 개씩만 존재하므로 그리디하게 접근
    for (int i = 0; i < N; i++) {
        long long weight = rope[i];
        weight = weight * (N - i);
        result = max(result, weight);
    }

    return result;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    rope.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> rope[i];
    }

    sort(rope.begin(), rope.end()); //밧줄 정렬

    cout << maxWeight() << endl;
    return 0;
}
