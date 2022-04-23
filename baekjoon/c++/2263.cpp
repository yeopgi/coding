#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100000 + 1;
int n;
vector<int> inorder, postorder;
int idx[MAX];

void Run(int inBegin, int inEnd, int postBegin, int postEnd)
{
    //모순
    if (inBegin > inEnd || postBegin > postEnd)
        return;

    int root = postorder[postEnd];
    cout << root << " ";
    //왼쪽
    Run(inBegin, idx[root] - 1, postBegin, postBegin + (idx[root] - inBegin) - 1);
    //오른쪽
    Run(idx[root] + 1, inEnd, postBegin + (idx[root] - inBegin), postEnd - 1);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    inorder.resize(n), postorder.resize(n);
    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    for (int i = 0; i < n; i++)
        cin >> postorder[i];

    for (int i = 0; i < n; i++)
        idx[inorder[i]] = i;

    Run(0, n - 1, 0, n - 1);

    return 0;
}