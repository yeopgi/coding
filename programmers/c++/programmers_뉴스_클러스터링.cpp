#include <algorithm>
#include <ctype.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int solution(string str1, string str2);
vector<string> makeArr(string str);

int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    cout << solution(str1, str2) << endl;
}

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> sv1 = makeArr(str1);
    vector<string> sv2 = makeArr(str2);
    int temp = sv2.size();
    if (!sv1.size() && !sv2.size())
        return 65536;

    for (int i = 0; i < sv1.size(); i++) {
        auto itr = find(sv2.begin(), sv2.end(), sv1[i]);
        if (itr != sv2.end()) {
            sv2.erase(itr);
            answer++;
        }
    }

    return 65536.0 * ((double)answer / (double)(sv1.size() + temp - answer));
}

vector<string> makeArr(string str) {
    vector<string> sv;
    string sub;

    for (int i = 0; i < str.length() - 1; i++) {
        if (!isalpha(str[i]) || !isalpha(str[i + 1]))
            continue;
        sub = str.substr(i, 2);

        transform(sub.begin(), sub.end(), sub.begin(), towlower);
        sv.push_back(sub);
    }
    return sv;
}