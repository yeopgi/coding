#include <iostream>
#include <vector>
using namespace std;

vector<int> preorder;

void Run(int start, int end)
{
    if (start == end) {
        return;
    }

    if (start == end - 1) {
        cout << preorder[start] << '\n';
        return;
    }

    int root = preorder[start];
    int idx = start + 1;
    int i;
    for (i = idx; i < end; i++) {
        if (root < preorder[i]) {
            break;
        }
    }

    Run(start + 1, i); // 좌
    Run(i, end);
    cout << root << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt = 0;
    int num;
    while (cin >> num) {
        cnt++;
        preorder.push_back(num);
    }

    Run(0, cnt);
    return 0;
}