#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num1, num2, minNum, repeat = 1;
    cin >> num1;
    cin >> num2;
    if(num2 == 1) {
        cout << -1 << '\n';
        return 0;
    }

    int primeSum = 0;
    for (int i = num1; i <= num2; i++) {
        if(i < 2) {
            continue; 
        }
        
        int j;
        bool isPrime = true;
        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }

        if(isPrime == true) {
            if(repeat == 1) {
                minNum = i;
                --repeat;
            }

            primeSum += i;
        }
    }

    if (primeSum == 0) {
        cout << -1 << '\n';
    } else {
        cout << primeSum << '\n'
             << minNum << '\n';
    }

    return 0;
}