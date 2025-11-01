#include <iostream>
#include <stack>
#include <array>
using namespace std;
array<int, 80000 + 1> buildings;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    long long tot=0;
    stack<int> st;
    for (size_t i = 1; i <= N; ++i)
    {
        int tmp;
        cin >> tmp;
        if(st.empty())
                {
            st.push(tmp);
            continue;
        }
        while (!st.empty() && st.top()<= tmp)
        {
            st.pop();
        }
        tot += st.size();
        st.push(tmp);
    }

    cout << tot << '\n';
}