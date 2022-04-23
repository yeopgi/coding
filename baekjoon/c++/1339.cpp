#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N;
const int MAX = 10;
string str[MAX];
int alpha[26];

int Run()
{
    for (int j = 0; j < N; j++) {
        int pow = 1;
        for (int i = str[j].size() - 1; i >= 0; --i)
        {
            int temp = (str[j][i]) - 'A';
            alpha[temp] += pow;
            pow *= 10;
        }
    }
    
    sort(alpha, alpha + 26);

    int ans = 0, num = 9;
    for (int i = 25; i >= 0; --i) {
        if (alpha[i] == 0) {
            break;
        }

        ans += alpha[i] * num--;
    }

    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> str[i];
    }

    int ans = Run();
    cout << ans << '\n';
    return 0;
}