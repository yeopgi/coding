#include <iostream>
#include <vector>
using namespace std;

const int MAX = 50;
int N;
int delStartNode;
pair<int, bool> parentAndisLeaf[MAX];
vector<int> ancestor[MAX];

int Run()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < ancestor[i].size(); j++) {
            if (ancestor[i][j] == delStartNode) {
                parentAndisLeaf[i].second = true;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (i != delStartNode) {
            parentAndisLeaf[parentAndisLeaf[i].first].second = true;            
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (!parentAndisLeaf[i].second) {
            cnt++;
        }
    }

    return cnt;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> parentAndisLeaf[i].first;
        parentAndisLeaf[parentAndisLeaf[i].first].second = true;
    }

    for (int i = 0; i < N; i++) {
        int temp = parentAndisLeaf[i].first;
        while (temp != -1) {
            ancestor[i].emplace_back(temp);
            temp = parentAndisLeaf[temp].first;
        }
    }

    cin >> delStartNode;
    parentAndisLeaf[delStartNode].second = true;
    parentAndisLeaf[parentAndisLeaf[delStartNode].first].second = false;

    cout << Run() << '\n';
    return 0;
}