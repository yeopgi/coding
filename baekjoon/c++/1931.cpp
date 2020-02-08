#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> information;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int meeting;
    cin >> meeting;
    information.resize(meeting + 1);
    for (int i = 1;i <= meeting; i++) {
        int start, end;
        cin >> start >> end;
        information[i].push_back(start);
        information[i].push_back(end);
    }

    return 0;
}