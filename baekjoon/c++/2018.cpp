

#include <iostream>
using namespace std;

int main() {
    int N;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int sum = 1;
    int right = 1;
    int left = 1;
    int tot = 0;
    while (right <= N && left <= right) {
        if (sum > N) {
            sum -= left;
            left += 1;
        } else if (sum == N) {
            tot += 1;
            sum -= left;
            left += 1;
        } else {
            right += 1;
            sum += right;
        }
    }
    cout << tot << endl;
    return 0;
}

