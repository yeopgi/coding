#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    vector<string> v = {{"c="}, {"c-"}, {"dz="}, {"d-"}, {"lj"}, {"nj"}, {"s="}, {"z="}};
    int alphabetCnt = 0;
    int wordIdx = 0;
    for (int i = 0; i < v.size(); i++) {
        while ((wordIdx = str.find(v[i])) != string::npos) {
            alphabetCnt += v[i].size();
            str.erase(wordIdx, v[i].size());
        }
    }
    
    cout << alphabetCnt << '\n';
    return 0;
}