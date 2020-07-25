#include <iostream>
#include <string>
using namespace std;
int solution(string s) {
    for (int i = s.length(); i > 1; i--) {
        for (int j = 0; j + i <= s.length(); j++) {
            bool flag = true;
            for (int k = 0; k < i / 2; k++) {
                if (s[j + k] != s[j + i - k - 1]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                return i;
            }
        }
    }

    return 1;
}