#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

vector<size_t> location;
set<int> s;

void install(int start, int end, int &remainCnt) 
{
    if (remainCnt == 0) {
        return;
    }
    int middle = (start + end) / 2;
    s.insert(middle);

    remainCnt--;
    install(start, middle, remainCnt);
    install(start, middle, remainCnt);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, C;
    cin >> N >> C;
    location.resize(N + 1);

    for (int i = 1; i <= N; i++){
        cin >> location[i];
    }
    sort(location.begin(), location.end());
    
    if (C == 2) {
        cout << location[N] - location[0] << '\n';
    }
    C -= 2;
    s.insert(location[0]);
    s.insert(location[N]);



    return 0;
}