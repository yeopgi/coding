#include <iostream>
#include <vector>
using namespace std;

vector<int> number;

void CreateNum(void)
{
    number.clear();

    for (int i = 1; (i * (i+1)) / 2 <= 1000; i++) {
        number.push_back((i * (i+1)) / 2);
    }
}

int IsExpress(const int &testNum) {
    for (int i = 0; i < number.size(); i++) {
        for (int j = 0; j < number.size(); j++) {
            for (int k = 0; k < number.size(); k++) {
                if (number[i] + number[j] + number[k] == testNum) {
                    return 1;
                } 
            }
        }
    }

    return 0;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    CreateNum();

    int test;
    cin >> test;
    while (test--) {
        int testNum;
        cin >> testNum;
        cout << IsExpress(testNum) << '\n';       
    }

    return 0;
}