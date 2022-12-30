#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int col = grid[0].size();
        const int row = grid.size();
        vector<int> v(col);
        v[0] = grid[0][0];
        for (int i = 1; i < col; i++) {
            v[i] = grid[0][i] + v[i - 1];
        }

        for (int i = 1; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (j == 0) {
                    v[j] = v[j] + grid[i][j];
                } else {
                    v[j] = min(v[j] + grid[i][j], v[j - 1] + grid[i][j]);
                }
            }
        }

        return v[col - 1];
    }
};

/*
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>> &grid) {
    const int col = grid[0].size();
    const int row = grid.size();
    int map[col] = {0};
    map[0] = grid[0][0];
    cout << col << '\n';

    for (int i = 1; i < col; i++) {
        map[i] = grid[0][i] + map[i - 1];
    }

    for (int i = 1; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j == 0) {
                map[j] = map[j] + grid[i][j];
            } else {
                map[j] = min(map[j] + grid[i][j], map[j - 1] + grid[i][j]);
            }
        }
    }

    return map[col - 1];
}
*/