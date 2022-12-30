#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str[101];
int strike[101];
int ball[101];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<string>> v(N);
    for (int i = 100; i <= 999; i++) {
        v[0].push_back(to_string(i));
    }

    for (int i = 0; i < N; i++) {
        cin >> str[i] >> strike[i] >> ball[i];
    }

    int l = 0;
    int temp = 0;
    string str1 = "";
    while (temp < 4) {
        for (int k = 0; k < v[temp].size(); k++) {
            int strikeCnt = 0, ballCnt = 0;
            str1 = v[temp][k];
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (str[temp][i] == str1[j]) {
                        if (i == j) {
                            strikeCnt++;
                            break;
                        } else {
                            ballCnt++;
                        }
                    }
                }
            }

            if (strikeCnt == strike[temp] && ballCnt == ball[temp]) {
                v[temp + 1][l++] = str1;
            }
        }

        temp++;
        l = 0;
    }

    cout << v[3].size() << '\n';
    return 0;
}