class Solution {
public:
    vector<int> twoSum(vector<int>& A, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < A.size(); ++i) {
            int t = target - A[i];
            if (m.count(t)) return { m[t], i };
            m[A[i]] = i;
        }
        return {};
    }
};

/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ret(2, 0);
        map<int, int> myMap;
        for (int i = 0; i < n; i++) {
            myMap.insert(make_pair(nums[i], i));
        }

        for (int i = 0; i < n; i++) {
            int temp = target - nums[i];
            map<int, int>::iterator iter = myMap.find(temp);
            if (iter != myMap.end() && iter->second != i) {
                ret[0] = i;
                ret[1] = iter->second;
                break;
            }
        }

        return ret;
    }
};
*/