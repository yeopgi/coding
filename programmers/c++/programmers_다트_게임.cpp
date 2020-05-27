#include <string>
#include <cctype>
#include <vector>
#include <cstring>
using namespace std;

vector<int> option(3, 0);
int solution(string dartResult) {
    int answer = 0;
    int maxValidLength = 3, startIdx = 0;
    for (int i = 0; i < 3; i++) {
        int offset = 0;
            string str = dartResult.substr(startIdx, maxValidLength - 1);
            if (isdigit(str[2])) {
                offset += 2;
                if (str[1] == 'S') {

                } else if (str[1] == 'D') {

                } else {

                }

            } else {
                offset += 3;
                option[i] = str[2] - '0';
            }

    }

    return answer;
}