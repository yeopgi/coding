#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> times) {
    int censorNum = times.size();
    sort(times.begin(), times.end());

    long long maxConsumeTime = n * (long long)(times[censorNum - 1]);
    long long minConsumeTime = times[0];
    long long answer = LLONG_MAX;

    long long maxNum = 0;
    while (minConsumeTime <= maxConsumeTime) {
        long long mid = (maxConsumeTime + minConsumeTime) / 2;
        long long sum = 0;
        for(auto i : times) {
            sum += mid / i;
        }

        if (n > sum) {                      // n명을 조사할 수 있는 시간이 부족한 경우
            minConsumeTime = mid + 1;
        } else {                            // n명을 조사할 수 있는 시간이 충분한 경우 -> n명 이상이거나 딱 n명이 됨
            answer = min(answer, mid);
            maxConsumeTime = mid - 1;
        }
    }

    return answer;
}