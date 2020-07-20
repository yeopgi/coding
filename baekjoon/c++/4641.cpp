#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int temp = 1;
    while (temp != -1) {
        v.clear();

        int temp2;
        while (true) {
            if (cin.eof() == true) {
                break;
            }

            cin >> temp2;
            if (temp2 == -1) {
                temp = -1;
                break;
            }

            if (temp2 == 0) {
                break;
            }

            v.push_back(temp2);
        }

        sort(v.begin(), v.end());

        int cnt = 0;
        for (int i = 0; i < v.size(); i++) {
            if (binary_search(v.begin(), v.end(), v[i] * 2)) {
                cnt++;
            }
        }

        if (temp != -1) {
            cout << cnt << '\n';
            cnt = 0;
        }
    }

    return 0;
}