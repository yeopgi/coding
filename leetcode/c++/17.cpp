#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    unordered_multimap<int, char> umm; // key, value

    void Run(int startIdx, int endIdx, string& digits, vector<string>& ans)
    {
        if (startIdx == endIdx) {
            return;
        }

        Run(startIdx + 1, endIdx, digits, ans); // 탐색 끝
        ans.emplace_back(umm.find((int)digits[startIdx])->second + umm.find((int)digits[endIdx])->second);
    }

    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            return vector<string>();
        }

        const int n = digits.size();
        char temp = 'a';
        umm.insert(1, temp++ - '0'), umm.insert(1, temp++ - '0'), umm.insert(1, temp++ - '0');
        umm.insert(2, temp++ - '0'), umm.insert(2, temp++ - '0'), umm.insert(2, temp++ - '0');
        umm.insert(3, temp++ - '0'), umm.insert(3, temp++ - '0'), umm.insert(3, temp++ - '0');
        umm.insert(4, temp++ - '0'), umm.insert(4, temp++ - '0'), umm.insert(4, temp++ - '0');
        umm.insert(5, temp++ - '0'), umm.insert(5, temp++ - '0'), umm.insert(5, temp++ - '0');
        umm.insert(6, temp++ - '0'), umm.insert(6, temp++ - '0'), umm.insert(6, temp++ - '0');
        umm.insert(7, temp++ - '0'), umm.insert(7, temp++ - '0'), umm.insert(7, temp++ - '0'), umm.insert(7, temp++ - '0');
        umm.insert(8, temp++ - '0'), umm.insert(8, temp++ - '0'), umm.insert(8, temp++ - '0');
        umm.insert(9, temp++ - '0'), umm.insert(9, temp++ - '0'), umm.insert(9, temp++ - '0'), umm.insert(9, temp++ - '0');

        for (int i = 2; i <= 9; i++) {
            for (int j = 0; j < 3; j++) {
                umm.insert(i, temp -'0');
                temp++;
            }
        }

        vector<string> ans;
        if (digits.size() == 1) {
            int temp = (int)digits[0];
            umm.find(temp)->second;
            //return ans.emplace_back(umm.find(temp)->second);
        }

        Run(0, n - 1, digits, ans);

        return ans;
    }
};