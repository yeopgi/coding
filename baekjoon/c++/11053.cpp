#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int d[1000 + 1];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int size;
    cin >> size;
    vector<int> v(size + 1);
    for(int i = 1; i <= size; i++) {
        cin >> v[i];
    }

    d[1] = 1;
    for(int i = 2; i <= size; i++) {
        int max = d[1], cnt = 0;
        for (int j = 1; j <= i; j++) {
            if (v[i] > v[j]) {
                cnt++;
            }
        }

        d[i] = d[i - 1];

    }

    cout << *max_element(d, d + size);
    return 0;
}