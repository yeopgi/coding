#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

string solution(vector< string > participant, vector< string > completion) {
    string answer = "";
    unordered_map<string, int> um;
    int participantSize = participant.size();
    int completionSize = completion.size();
    for (int i = 0; i < participantSize; i++) {
        um[participant[i]]++;
    }

    for (int i = 0; i < completionSize; i++) {
        um[completion[i]]--;
    }

    for (auto &x : um) {
        if (x.second == 1) {
            answer = x.first;
            break;
        }
    }

    return answer;
}