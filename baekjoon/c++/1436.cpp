#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int input;
    cin >> input;
    int movieSeries = 0;
    for (int i = 666;; i++) {
        int temp = i;
        int isSequence = false;
        while (temp) {
            if (temp % 10 == 666) {
                isSequence = true;
                break;
            } 

            temp = temp / 10;            
        }

        if (isSequence) {
            movieSeries++;
            if (movieSeries == input) {
                cout << i << '\n';
                return 0;
            }
        }
    }

    return 0;
}
