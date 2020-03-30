#include <string>
#include <vector>

using namespace std;

long long d[81];

long long solution(int N) {
    long long answer = 0;
    d[2] = 1, d[1] = 1;
    for (int i = 3; i <= N; i++) {
        d[i] = d[i - 1] + d[i - 2];
    }

    answer = d[N] * 2 + (d[N - 1] + d[N]) * 2;
    return answer;
}