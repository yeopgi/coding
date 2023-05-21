#include <array>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000;
int N, K;
int d[MAX + 1];
array<int, MAX + 1> spend;
vector<int> connection[MAX + 1];
int start_x, start_y;
int end_x, end_y;
int in_out_cnt = 0;

void Run(int planet_x, int planet_y, int radius)
{
    const int max_range_x = planet_x + radius;
    const int max_range_y = planet_y + radius;
    const int min_range_x = planet_x - radius;
    const int min_range_y = planet_y - radius;
    if ((start_x > min_range_x && start_x < max_range_x) && (start_y > min_range_y && start_y < max_range_y)) {
        ++in_out_cnt;
        return;
    }

    if ((end_x > min_range_x && end_x < max_range_x) && (end_y > min_range_y && end_y < max_range_y)) {
        ++in_out_cnt;
        return;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, cnt;
    
    cin >> T;
    int in_planet_cnt;
    while (T--) {
        cin >> start_x >> start_y >> end_x >> end_y;
        uint32_t planet_cnt;
        cin >> planet_cnt;
        for (int i = 1; i <= planet_cnt; i++) {
            int planet_x, planet_y, radius;
            cin >> planet_x >> planet_y >> radius;
            Run(planet_x, planet_y, radius);
        }
    }

    return 0;
}