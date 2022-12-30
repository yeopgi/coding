#include <iostream>
#include <vector>
#define max_int 21
#define max_val 2147483647
using namespace std;

int n, a[max_int][max_int], start_sum, link_sum, start_first, start_second, link_first, link_second, result = max_val;
vector<int> start, link;

int min(int a, int b) {
    return a < b ? a : b;
}

int abs(int a) {
    if (a < 0)
        a = a * -1;
    return a;
}

void go(int idx) {
    if (idx == n + 1) {
        if (start.size() == n / 2 && link.size() == n / 2) {
            start_sum = 0;
            link_sum = 0;
            for (int i = 0; i < n / 2; i++) {
                for (int j = i + 1; j < n / 2; j++) {
                    if (i == j)
                        continue;

                    start_first = start[i];
                    start_second = start[j];
                    start_sum += a[start_first][start_second] + a[start_second][start_first];
                    link_first = link[i];
                    link_second = link[j];
                    link_sum += a[link_first][link_second] + a[link_second][link_first];
                }
            }

            result = min(result, abs(start_sum - link_sum));
        }

        return;
    }

    start.push_back(idx);
    go(idx + 1);
    start.pop_back();

    link.push_back(idx);
    go(idx + 1);
    link.pop_back();
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    go(1);

    printf("%d\n", result);
}