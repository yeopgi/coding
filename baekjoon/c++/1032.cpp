#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> v;

void PrintPattern(size_t stringLength) 
{
    for (size_t i = 0; i < stringLength; i++) {
        char c = v[0][i];
        size_t j;
        for (j = 1; j < v.size(); j++) {
            if (c != v[j][i]) {
                cout << '?';
                j = 51;
            }
        }

        if (j != 52) {
            cout << c;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int stringCnt;
    size_t length;
    cin >> stringCnt;
    if (stringCnt == 1) {
        string str;
        cin >> str;
        cout << str << '\n';
        return 0;
    }

    while (stringCnt--) {
        string str;
        cin >> str;
        length = str.size();
        v.push_back(str);
    }

    PrintPattern(length);

    cout << '\n';
    return 0;
}