#include <iostream>
#include <unordered_map>
using namespace std;

const int MAX = 50;
int N;
unordered_multimap<int, int> parentChild;
unordered_map<int, int> childParent;
int cnt = 0;
int emptyCnt = 0;

int Run(int srcDelNode)
{
    if (!parentChild.count(srcDelNode))
    {
        int parent = childParent.find(srcDelNode)->second;
        if (parentChild.count(parent) - 1 > 0) // 부모가 단말노드가 아니다.
        {
            return 1;
        }

        return 0;
    }

    int delNode = srcDelNode;
    auto iter = parentChild.equal_range(delNode);
    int temp = 0;
    for (auto iter2 = iter.first; iter2 != iter.second; iter2++) {
        temp += Run(iter2->second);
    }

    if (parentChild.count(srcDelNode) - 1 > 0) {
        return emptyCnt - temp + 1;
    } else {
        return emptyCnt - temp;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        if (i != 0) {
            parentChild.insert({temp, i}); // (parent, child)
            childParent.insert({i, temp}); // (parent, child)
        }
    }

    for (int i = 0; i < N; i++) {
        if (!parentChild.count(i)) {
            emptyCnt++;
        }
    }

    int delStartNode;
    cin >> delStartNode;
    if (delStartNode == 0) {
        cout << 0 << '\n';
        return 0;
    }
    
    int ans = Run(delStartNode);

    cout << ans << '\n';
    return 0;
}