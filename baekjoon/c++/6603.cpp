#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int element_cnt;
const int lotto_cnt = 6;
array<int, 49 + 1> input_array;

void remark(const int idx, int check_cnt, array<int, lotto_cnt>& lotto)
{
    if (lotto_cnt == check_cnt) {
		for (const auto& i : lotto) {
            cout << i << ' ';
        }

        cout << '\n';
        return;
    }

    for (int i = idx; i <= element_cnt; i++) {
        lotto[check_cnt] = input_array[i];
        remark(i + 1, check_cnt + 1, lotto);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cin >> element_cnt;
        if (!element_cnt) {
            break;
        }

        for (int i = 1; i <= element_cnt; i++) {
            int input_cnt;
            cin >> input_cnt;
            input_array[i] = input_cnt;
        }

        const int check_cnt = 0;
        array<int, lotto_cnt> lotto{ 0, };
        remark(1, check_cnt, lotto);

        cout << '\n';
    }

    return 0;
}
