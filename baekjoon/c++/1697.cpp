#include <iostream>
#include <queue>
using namespace std;

bool visit[100000 + 1];
int me, brother;
queue<pair<int, int>> q;

int Finding(int location, int time)
{
    if (!visit[location]) {
        visit[location] = true;
        if (location == brother) {
            cout << time;
            return 0;
        }

        q.push(make_pair(location, time));
    }

    return -1;
}

void Measure(int start, int time) 
{
    q.push(make_pair(start, time));

    while (!q.empty()) {
        int location = q.front().first;
        int spendTime = q.front().second;
        q.pop();
        visit[location] = true;
        if(Finding(location + 1, spendTime + 1) == 0) {
            return;
        }

        if (Finding(location - 1, spendTime + 1) == 0) {
            return;
        }

        if (Finding(location * 2, spendTime + 1) == 0) {
            return;
        }
    }
}

int main(void) 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> me >> brother;
    Finding(me, 0);
    

    return 0;
}