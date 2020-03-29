#include <stdio.h>
#include <algorithm>
using namespace std;

const int kMaxCnt = 17;
int n, t[kMaxCnt], p[kMaxCnt], d[kMaxCnt], result;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &t[i], &p[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (i + t[i] <= n + 1) {
            d[i + t[i]] = max(d[i + t[i]], d[i] + p[i]);
            result = max(result, d[i + t[i]]);
        }

        d[i + 1] = max(d[i + 1], d[i]);
        result = max(result, d[i + 1]);
    }

    printf("%d\n", result);
}