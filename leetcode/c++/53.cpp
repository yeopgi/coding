#include <algorithm>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int numsSize = nums.size();
        vector<int> d(numsSize, 0);
        d[0] = nums[0];
        for (int i = 1; i < numsSize; i++) {
            d[i] = max(d[i - 1] + nums[i], nums[i]);
        }

        return *max_element(d.begin(), d.end());
    }
};