class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int dMax = 1, dMin = 1;
        for (int i : nums) {
            int a = i * dMax, b = i * dMin;
            dMax = max({b, a, i});
            dMin = min({a, b, i});
            res = max(res, dMax);
        }

        return res;
    }
};