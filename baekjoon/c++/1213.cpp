// 팰린드롬 생성 조건 
// 1. 모든 문자가 짝수개
// 2. 하나의 문자가 홀수개 있고 나머지 문자들이 짝수개 있다.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int alphabet[26];

int main(void)
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            alphabet[s[i] - 'A']++;
        }

        vector<pair<char, int>> v;
        vector<char> middle;
        bool flag = false;
        for (int i = 0; i < 26; i++)
                 //홀수개인 문자가 2개 이상일 수 없습니다.
                 if (alphabet[i] % 2 && flag) {
                     cout << "I'm Sorry Hansoo\n";
                     return 0;
                 } else if (alphabet[i] % 2 && !flag) {
                     v.push_back({i + 'A', alphabet[i] - 1});

                     middle.push_back(i + 'A');

                     flag = true;
                 } else
                     v.push_back({i + 'A', alphabet[i]});

        string result;
        //사전순으로 정렬한 상태에서 반씩 추가해주r고
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < (v[i].second / 2); j++) {
                result += v[i].first;
            }
        }

        for (int i = 0; i < result.size(); i++) {
            cout << result[i];
        }

        if (middle.size()) {
            cout << middle[0];
        }

        for (int i = result.size() - 1; i >= 0; i--) {
            cout << result[i];
        }
        
        cout << '\n';
        return 0;
}