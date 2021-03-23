#include <string>
#include <cctype>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

vector<int> option(3,0);
vector<int> sqrtList(3, 0);
vector<int> scoreList(3, 0);

int Calculation(char sqrtSrc, int number) {
    int totalScore = 0;
    if (sqrtSrc == 'S') {
        totalScore = pow(number, 1);
    } else if (sqrtSrc == 'D') {
        totalScore = pow(number, 2);
    } else {
        totalScore = pow(number, 3);
    }

    return totalScore;
}

int solution(string dartResult) {
    int answer = 0, idx = option.size(), digitIdx = 2;
    stack<int> st;
    for (int i = 0; i < dartResult.size(); i++) {
        st.push(dartResult[i]);
    }

    int total = 0, temp = 0;
    int cnt = 0;
    while (!st.empty()) {
        char c = st.top();
        st.pop();

        if (isdigit(c)) {
            scoreList.push_back(Calculation(sqrtList[cnt], c - '0'));
            if (option[cnt] == '*') {
                scoreList[cnt] *= 2;
            } else if (option[cnt] == '#'){
                if (option[cnt + 1] == '*') {
                    scoreList[cnt] *= -2;
                } else {
                    scoreList[cnt] *= -1;
                }
            }

            cnt++;
        } else {
            if (isalpha(c)) {
                sqrtList.push_back(c);
            } else {
                option[cnt] = c;
            }
        }
    }

    for (int i = 0; i < scoreList.size(); i++) {
        answer += scoreList[i];
    }

    return answer;
}