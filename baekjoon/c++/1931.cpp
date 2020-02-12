#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct information
{
    int start, end;
}information;

void compare(information inform1, information inform2)
{  
    /*
    if (inform1.end == inform2.end) {
        return inform1.start < inform2.start;
    } else {
        return inform1.end < inform2.end;
    }*/
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int meeting;
    cin >> meeting;
    vector<information> v(meeting);
    for (int i = 1;i <= v.size(); i++) {
        cin >> v[i].start >> v[i].end;
    }

    sort(v.begin(), v.size(), compare);

    return 0;
}