<<<<<<< HEAD
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
=======
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int d[1000 + 1];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int size;
    cin >> size;
    vector<int> v(size + 1);
    for(int i = 1; i <= size; i++) {
        cin >> v[i];
    }

    d[1] = 1;
    for(int i = 2; i <= size; i++) {
        int max = d[1], cnt = 0;
        for (int j = 1; j <= i; j++) {
            if (v[i] > v[j]) {
                cnt++;
            }
        }

        d[i] = d[i - 1];

    }

    cout << *max_element(d, d + size);
    return 0;
}
>>>>>>> b24fca794516c0210d9885c8476e3cffd4833676
