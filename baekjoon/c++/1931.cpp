#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N; //<=100000
int cBegin[100000], cEnd[100000]; //conference 시작시간, 끝나는 시간

int schedule(void)
{
    vector<pair<int, int>> order;
    for (int i = 0; i < N; i++)
        order.push_back(make_pair(cEnd[i], cBegin[i]));

    sort(order.begin(), order.end());
    //earliest: 다음 회의가 시작할 수 있는 가장 빠른 시간
    //selected: 지금까지 선택한 회의의 수
    int earliest = 0, selected = 0;
    for (int i = 0; i < order.size(); i++) {
        int meetingBegin = order[i].second, meetingEnd = order[i].first;
        if (earliest <= meetingBegin) {
            //earliest를 마지막 회의가 끝난 시간 이후로 갱신
            earliest = meetingEnd;
            selected++;
        }
    }
    return selected;
}

int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> cBegin[i] >> cEnd[i];

    cout << schedule() << endl;
    return 0;
}