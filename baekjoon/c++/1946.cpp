#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> N;
        vector<pair<int, int>> score(N); // document, interview
        for (int i = 0; i < N; i++) {
            int documentLevel, interviewLevel;
            cin >> documentLevel >> interviewLevel;
            score[i] = {documentLevel, interviewLevel};
        }

        sort(score.begin(), score.end());

        int interviewLevel = score[0].second;
        int res = 1;
        for (int i = 1; i < N; i++) {
            if (interviewLevel > score[i].second) {
                res++;
                interviewLevel = score[i].second;
            }
        }

        cout << res << '\n';
    }

    return 0;
}