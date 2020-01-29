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
