#include <cstring>
#include <algorithm>
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int row = grid.size() + 1;
        const int col = grid[0].size() + 1;
        int map[row][col];
        memset(map, 0, sizeof(map));

        for (int i = 0; i < row - 1; i++) {
            for (int j = 0; j < col - 1; j++) {
                map[i + 1][j + 1] = grid[i][j];
            }
        }

        for (int i = 2; i < col; i++) {
            map[1][i] = map[1][i - 1] + map[1][i];
        }

        for (int i = 2; i < row; i++) {
            map[i][1] = map[i - 1][1] + map[i][1];
        }


        for (int i = 2; i < row; i++) {
            for (int j = 2; j < col; j++) {
                map[i][j] = min(map[i - 1][j], map[i][j - 1]) + map[i][j];
            }
        }

        return map[row - 1][col - 1];
    }
};