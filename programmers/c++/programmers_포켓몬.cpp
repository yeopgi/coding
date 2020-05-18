#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

priority_queue<int> pq;

int solution(vector<int> nums) {
    int answer = 0;
    int length = nums.size();
    int getPocketMonSize = length / 2;
    for (int i = 0; i < length; i++) {
        pq.push(nums[i]);
    }

    int cnt = 0;
    while (!pq.empty()) {
        int target = pq.top();
        pq.pop();

        cnt++;
        if (cnt == getPocketMonSize) {
            return cnt;
        }

        while (!pq.empty()) {
            if (pq.top() == target) {
                target = pq.top();
                pq.pop();
            } else {
                target = pq.top();
                cnt++;
                pq.pop();
                if (cnt == getPocketMonSize) {
                    return cnt;
                }
            }
        }
    }

    return cnt;
}
