#include <string>
#include <cctype>
#include <vector>
#include <cmath>
#include <stack>
#include <iostream>

#define INIT_VALUE 987654321
using namespace std;

vector<int> option(4,INIT_VALUE);
vector<int> alphabet(4, 0);
vector<int> score(4, 0);
vector<int> digit(4, 0);

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
    int answer = 0;
    int cnt = 0;
    for (int i = 0; i < dartResult.size(); i++) {
        if (isdigit(dartResult[i])) {
            cnt++;
            if (isdigit(dartResult[i + 1])) {
                string str = "";
                str = dartResult.substr(i, 2);
                digit[cnt] = stoi(str);
                i++;
                continue;
            }
            digit[cnt] = dartResult[i] -'0';
        } else {
            if (isalpha(dartResult[i])) {
                alphabet[cnt] = dartResult[i];
            } else {
                option[cnt] = dartResult[i];
            }
        }
    }

    for (int i = 1; i <= 3; i++) {
        score[i] = Calculation(alphabet[i],digit[i]);
        if (option[i] != INIT_VALUE) {
            if (option[i] == '#') {
                score[i] *= -1;/*
                if (i - 1 >= 1) {
                    if (option[i - 1] == '*') {
                        score[i] *= 2;
                    }
                }*/
            } else {
                score[i] *= 2;
                if (i - 1 >= 1) {
                    score[i - 1] *= 2;
                }
            }
        }
    }

    for (int i = 1; i <= score.size(); i++) {
        answer += score[i];
    }

    return answer;
}