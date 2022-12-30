#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int progressesListCnt = progresses.size();
    for (int j = 0; j < progressesListCnt; j++) {
        progresses[j] = (int)ceil((double)(100 - progresses[j]) / speeds[j]);
    }

    int offset = 0;
    for (int i = 0; i < progressesListCnt; i += offset) {
        if (i == progressesListCnt - 1) {
            answer.push_back(1);
            break;
        }
        int complete = 0;
        int temp = progresses[i];
        complete++;
        int j;
        for (j = i + 1; j < progressesListCnt; j++) {
            if (temp >= progresses[j]) {
                complete++;
            } else {
                offset = complete;                
                break;
            }
        }
        
        answer.push_back(complete);
        
        if (j == progressesListCnt) {
            break;
        }
    }

    return answer;
}