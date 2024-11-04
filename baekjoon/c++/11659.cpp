#include <iostream>
using namespace std;

int dp[100000 + 1];
int numbers[100000 + 1];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int len, case_cnt;
    cin >> len >> case_cnt;
    for (size_t i = 1 ; i <= len; ++i) {
        int temp;
        cin >> temp;
        numbers[i] = temp;
        dp[i] = dp[i - 1] + numbers[i];
    }

    for(size_t i = 1; i <= case_cnt; ++i) {
        int start,end;
        cin >> start >> end;
        cout << dp[end] - dp[start - 1] << '\n';
    }
}