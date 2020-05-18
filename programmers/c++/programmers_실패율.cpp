#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef pair<double, int> pp;

bool compare(const pp &a, const pp &b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pp> fail;
    int answerSize = answer.size();
    int totalPeople = stages.size();
    int maxNum = *max_element(answer.begin(), answer.end());
    vector<int> peopleInStage(maxNum + 1);
    for (int i = 0; i <= maxNum; i++) {
        peopleInStage[stages[i]]++;
    }

    vector<double> percent(maxNum + 1);
    percent[0] = peopleInStage[0] / totalPeople;
    fail.push_back({0, percent[0]});

    int temp = peopleInStage[0];
    for (int i = 1; i <= maxNum; i++) {
        if (peopleInStage[i] != 0) {
            percent[i] = peopleInStage[i] / (totalPeople - temp);
            temp += peopleInStage[i];
            fail.push_back({i, percent[i]});
        }
    }

    sort(fail.begin(), fail.end(), compare);

    for (int i = 0; i < fail.size(); i++) {
        answer.push_back(fail[i].second);
    }

    return answer;
}