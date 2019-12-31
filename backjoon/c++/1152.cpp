#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    getline(cin, str);

    int wordCnt = 0;
    for (int i = 0; i < str.size(); i++) {
        if (i == 0) {
            if(str[i] = ' ') {
                continue;
            }
        } else {
            if (str[i] = ' ') {
                wordCnt++;
            }
        }
    }

    cout << wordCnt + 1 << endl;
    return 0;
}