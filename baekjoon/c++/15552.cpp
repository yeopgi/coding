#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test;
    cin >> test;
    while (test--) {
        int num1, num2;
        cin >> num1 >> num2;
        cout << num1 + num2 << '\n';
    }
    
    return 0;
}