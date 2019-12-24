#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    getline(cin, str);

    int wordCnt = 0;
    char prev;
    for (int i = 0; i < str.size(); i++) {
        prev = str[i];
        if (str[i] == ' ') {
            if (i == 0 || i == str.size() - 1) {
                continue;
            }
            wordCnt++;
        }
    }

    cout << wordCnt + 1 << endl;
    return 0;
}