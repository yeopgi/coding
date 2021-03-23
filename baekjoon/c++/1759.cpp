#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

int L, C;
vector<char> vowel;      // 모음
vector<char> consonant;  // 자음
set<string> s;

void Run(int vowelIdx, int consonantIdx, int vowelCnt, int consonantCnt, string current)
{
    int n = current.size();
    if (n == L && vowelCnt >= 1 && consonantCnt >= 2)
    {
        sort(current.begin(), current.end());
        s.insert(current);
        return;
    }

    if (n == L) {
        return;
    }

    for (int i = vowelIdx + 1; i < vowel.size(); i++) {
        Run(i, consonantIdx, vowelCnt + 1, consonantCnt, current + vowel[i]);
    }

    for (int i = consonantIdx + 1; i < consonant.size(); i++) {
        Run(vowelIdx, i, vowelCnt, consonantCnt + 1, current + consonant[i]);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> L >> C;
    for (int i = 0; i < C; i++) {
        char input;
        cin >> input;
        if (input == 'a' || input == 'e' || input == 'i' || input == 'o' || input == 'u') {
            vowel.push_back(input);
        } else {
            consonant.push_back(input);
        }
    }

    sort(vowel.begin(), vowel.end());
    sort(consonant.begin(), consonant.end());

    Run(-1, -1, 0, 0, "");

    for (auto i : s) {
        cout << i << '\n';
    }
    
    return 0;
}