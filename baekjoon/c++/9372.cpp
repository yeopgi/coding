#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test;
    cin >> test;
    while (test--) {
        int country, airplane;
        cin >> country >> airplane;
        for (int i = 0; i < airplane; i++) {
            int temp1, temp2;
            cin >> temp1 >> temp2;
        }

        cout << country - 1 << '\n';
    }

    return 0;
}