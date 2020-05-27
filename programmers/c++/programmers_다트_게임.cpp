#include <string>
#include <cctype>
#include <vector>
#include <cstring>
using namespace std;

vector<int> option(3, 0);
int solution(string dartResult) {
    int answer = 0;
    int maxValidLength = 3;
    for (int i = 0; i < 3; i++) {
        int offset = 0;
        for (int j = 0; j < dartResult.size(); j += offset) {
            string str = dartResult.substr(j, maxValidLength - 1);
            if (isdigit(str[2])) {
                offset += 2;
                if (str[1] == 'S') {

                } else if (str[1] == 'D') {

                } else {

                }

            } else {
                offset += 3;
                v.push_back(atoi(str[2]));
            }

        }
    }

    return answer;
}