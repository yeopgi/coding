#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    const int n = prices.size();
    vector<int> answer(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && prices[st.top()] > prices[i]) {
            auto top = st.top();
            answer[top] = i - top;
            st.pop();
        }

        st.push(i);
    }

    while (!st.empty()) {
        int top = st.top();
        answer[top] = n - 1 - top;
        st.pop();
    }

    return answer;
}