#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[101][2];
vector<int> src;
vector<int> dst;
bool first_try = true;

void cal(int start_idx)
{
    if (first_try) {
        src.push_back(arr[0][start_idx]);
        dst.push_back(arr[1][start_idx]);
        first_try = false;
    } else {
        src.push_back(arr[0][start_idx]);
        dst.push_back(arr[1][start_idx]);
        sort(src.begin(), src.end());
        sort(dst.begin(), dst.end());

        int i;
        for (i = 0; i < src.size(); i++) {
            if (src[i] != dst[i]) {
                break;
            }
        }

        if (i != src.size()) {
            src.pop_back();
            dst.pop_back();
        }
    }

    for (int i = start_idx; i <= N; i++) {
        first_try = true;
        cal(i);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;
        arr[0][i] = i;
        arr[1][i] = temp;
    }

    cal(1);

    cout << src.size() << '\n';
    return 0;
}