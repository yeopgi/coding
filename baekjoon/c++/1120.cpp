#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str1, str2;
    cin >> str1 >> str2;
    vector<int> v;
    for (int i = 0; i <= str2.size() - str1.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < str1.size(); j++) {
            if (str1[j] != str2[i + j]) {
                cnt++;
            }
        }

        v.push_back(cnt);
    }

    cout << *min_element(v.begin(), v.end()) << '\n';
    return 0;
}