#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int main(void) 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test;
    cin >> test;
    while (test--) {
        int document, index;
        cin >> document >> index;
        v.clear();

        //v.resize(document);

        for (int i = 0; i < document; i++) {
            int value;
            cin >> value;
            if (i != index) {
                v.push_back(make_pair(value, -1));
            } else { 
                v.push_back(make_pair(value, index));
            }
        }

        sort(v.begin(), v.end(), greater<>());

        for (int i = 0; i < v.size(); i++) {
            
        }
    }

    return 0;
}