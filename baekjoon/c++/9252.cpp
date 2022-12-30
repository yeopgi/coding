#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 1000;
string str1, str2;
string result;
int cache[MAX + 1][MAX + 1];

int Run(int idx1, int idx2)
{
    if (idx1 == str1.size() || idx2 == str2.size()) {
        return 0;
    }

    int &result = cache[idx1][idx2];
    if (result != -1) {
        return result;
    }

    result = max(Run(idx1 + 1, idx2), max(Run(idx1, idx2 + 1), Run(idx1 + 1, idx2 + 1) + (str1[idx1] == str2[idx2])));
    return result;
}

void reconstruct(int idx1, int idx2)
{
    //기저 사례(인덱스 범위 초과시 그만)
    if (idx1 == str1.size() || idx2 == str2.size())
        return;
    //공통부분 찾았을 경우
    if (str1[idx1] == str2[idx2]) {
        result += str1[idx1];
        reconstruct(idx1 + 1, idx2 + 1);
    }

    //s1의 인덱스를 추가했을 경우 s2의 인덱스를 추가했을 때보다 LCS의 길이가 크거나 같은 경우
    else if (cache[idx1 + 1][idx2] >= cache[idx1][idx2 + 1])
        reconstruct(idx1 + 1, idx2);
    else
        reconstruct(idx1, idx2 + 1);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> str1;
    cin >> str2;
    memset(cache, -1, sizeof(cache));

    cout << Run(0, 0) << '\n';
    reconstruct(0, 0);
    
    cout << result << '\n';
    return 0;
}