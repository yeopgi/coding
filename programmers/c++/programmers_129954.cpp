#include <iostream>
#include <vector>
using namespace std;

int Making(vector<int> nums) {
    int sum;
    int size = nums.size();
    int cnt = 0;
    for (int i = 0; i < size - 2; i++) {
        for (int j = i + 1; j < size - 1; j++) {
            for (int k = j + 1; k < size; k++) {
                sum = nums[i] + nums[j] + nums[k];
                int l; bool flag = true;
                for (l = 2; l * l <= sum; l++) {
                    if (sum % l == 0) {
                        flag = false;
                        // 소수 아닌 경우
                        break;
                    }
                }
                
                if (flag) {
                    cnt++;
                }
            }
        }
    }

    return cnt;
}


int solution(vector<int> nums) {
    int answer = -1;
    answer = Making(nums);

    return answer;
}