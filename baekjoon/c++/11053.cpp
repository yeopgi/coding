#include <iostream>
#include <algorithm>
using namespace std;

int d[1001];
int a[1001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        d[i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j]) {
                if (d[i] < d[j] + 1) {
                    d[i] = d[j] + 1;
                }
            }
        }
    }

    cout << *max_element(&d[1], &d[N + 1]) << '\n';
    return 0;
}

/*
#include <cstdio>
#include <algorithm>
using namespace std;

int main(void){
    int N;
    int Dp[1010] = {};
    int A[1010] = {};
    int max = 0;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        Dp[i] = 1;
    }

    for (int i = 2; i <= N; i++)
    {
        int temp = 0;
        for (int j = 1; j < i; j++) {
            if (A[i]>A[j]){
                if (temp < Dp[j])
                    temp = Dp[j];
            }
        }
        Dp[i] = temp + 1;
    }

    printf("%d\n", *max_element(Dp, Dp + (N + 1)));

    return 0;
}

*/