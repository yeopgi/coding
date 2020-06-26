#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<string> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    vector<string> vResult;
    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        if(binary_search(v.begin(), v.end(), str)) {
            vResult.push_back(str);
        }
    }
    sort(vResult.begin(), vResult.end());

    cout << vResult.size() << '\n';
    for (int i = 0; i < vResult.size(); i++) {
        cout << vResult[i] << '\n';
    }
    return 0;
}
