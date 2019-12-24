#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCase;
    cin >> testCase;
    while (testCase--) {
      
        string str;
        cin.ignore('\n');
        getline(cin, str);
        cout << "str : " << str << endl;
        for (int i = 2; i < str.size(); i++) {
            cout << "asd" << endl;
            int repeat = static_cast<int>(str[0] - '0');
            cout << "repeat : " << repeat << endl;

            while (repeat--) {
                cout << str[i];
            }
        }
    }

    cout << '\n';
    return 0;
}