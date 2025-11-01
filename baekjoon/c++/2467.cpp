#include <iostream>
#include <vector>
#include <cmath>

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<long long> solutions(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> solutions[i];
    }

    int left = 0;
    int right = n - 1;

    long long result_left = solutions[left];
    long long result_right = solutions[right];
    long long min_abs_sum = std::abs(result_left + result_right);

    while (left < right) {
        long long current_sum = solutions[left] + solutions[right];
        long long current_abs_sum = std::abs(current_sum);

        if (current_abs_sum < min_abs_sum) {
            min_abs_sum = current_abs_sum;
            result_left = solutions[left];
            result_right = solutions[right];
        }

        if (current_sum < 0) {
            ++left;
        } else {
            --right;
        }
    }

    std::cout << result_left << ' ' << result_right << '\n';

    return 0;
}