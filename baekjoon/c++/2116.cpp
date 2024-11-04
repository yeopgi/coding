#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr uint32_t       MAX_SQUARE_MAX_CNT     = 10000 + 1;
constexpr uint32_t       CURRENT_UPPER__MAX_IDX = 4;
vector<uint32_t>         square_vec[MAX_SQUARE_MAX_CNT];
pair<uint32_t, uint32_t> pair_vec[4];
uint32_t                 square_cnt;
uint32_t                 max_ans = 0;
uint32_t maxNum_arry[MAX_SQUARE_MAX_CNT][CURRENT_UPPER__MAX_IDX] = {0};
uint32_t compatible[6 + 1]                                           = {0};

uint32_t Run(const uint32_t under_idx, const uint32_t curr_layer,
              const uint32_t curr_total) {
    if (curr_layer > square_cnt) {
        if (max_ans < curr_total) {
            max_ans = curr_total;
        }

        return 0;
    }

    uint32_t exception_idx = 0;
    uint32_t upper_idx     = 0;
    for (int i = 1; i <= 6; i++) {
        if (i == under_idx) {
            upper_idx = compatible[i];
            break;
        }
    }

    for (size_t i = 1; i <= 6; i++) {
        if (under_idx == i || upper_idx == i) {
            continue;
        }

        maxNum_arry[curr_layer][under_idx] =
            max(maxNum_arry[curr_layer][under_idx], square_vec[curr_layer][i]);
    }

    Run(upper_idx, curr_layer + 1,
         curr_total + maxNum_arry[curr_layer][under_idx]);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> square_cnt;
    for (size_t i = 1; i <= square_cnt; ++i) {
        square_vec[i].resize(7);
        for (uint32_t j = 1; j <= 6; j++) {
            uint32_t temp;
            cin >> square_vec[i][j];
        }
    }

    pair_vec[1] = {1, 6};
    compatible[1] = 6, compatible[6] = 1;
    pair_vec[2] = {2, 4};
    compatible[2] = 4, compatible[4] = 2;
    pair_vec[3] = {3, 5};
    compatible[3] = 5, compatible[5] = 3;

    // 어느면이 윗면인지 고려되있지 않음.
    for (size_t i = 1; i <= 3; i++) {
        Run(square_vec[1][pair_vec[i].first], 1, 0);
        Run(square_vec[1][pair_vec[i].second], 1, 0);
    }

	cout << max_ans << '\n';

    return 0;
}

