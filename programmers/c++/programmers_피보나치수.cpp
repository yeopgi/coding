#include <string>
#include <vector>

using namespace std;

long long arry[100001];

int solution(int n) {
    int answer = 0;
    
    arry[0] = 0, arry[1] = 1;
    for (int i = 2; i <= n; i++) {
        arry[i] = (arry[i - 2] + arry[i - 1]) % 1234567;
    }
    
    answer = arry[n];
    return answer;
}