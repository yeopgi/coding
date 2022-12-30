#include <iostream>
using namespace std;

bool eratosthenes[123456 * 2 + 1];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 2; i * i <= 123456 * 2 ; i++) {
        if (eratosthenes[i] != true) {
            for (int j = i * i; j <= 123456 * 2; j += i) {
                eratosthenes[j] = true;
            }
        }
    }

    while (true) {
        int input;
        cin >> input;
        if(input == 0) {
            return 0;
        }
        
        if (input == 1) {
            cout << 1 << '\n';
            continue;
        }        

        int cnt = 0;
        for (int i = input +1 ; i <= 2 * input; i++) {
            if (eratosthenes[i] == false) {
                cnt++;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}