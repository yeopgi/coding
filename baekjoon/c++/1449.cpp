#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l;
    cin >> n >> l;
    
    array<int, 1000 + 1> leaks = {0};
    for (size_t i =1; i <= n; ++i)      {
        cin >> leaks[i];
    }
    if (l == 1){
        cout << n << '\n';
        return 0;
    }
    sort(leaks.begin() + 1, leaks.begin() + n + 1);
    size_t start_idx=1;
    int tot = 0;
    for (size_t i = 2; i <=n; ++i) {
        if (leaks[i]  >= leaks[start_idx] + l ) {
            start_idx = i;
            tot++;
            break;
        }
    }
    
    // while (start_idx < n) {
    //     bool escape= false;
    //     const float tmp = start + l - 0.5;
    //     for (size_t i = start_idx + 1; i <= n; ++i) {
    //         const float leak_point = static_cast<float>(leaks[i]);
    //         if (leak_point >  tmp) {
    //             start_idx = i;
    //             start = leak_point - 0.5;
    //             tot++;
    //             escape= true;
    //             break;
    //         }
    //     }
    //     if (!escape) {
    //         start_idx++;
    //     }
    //     // cout << "start :" << start << ' ';
    // }
    cout << tot + 1 << '\n';


    return 0;
}

// 4 2
// 1 2 100 101

// 4 3
// 1 2 3 4

// 3 1
// 3 2 1