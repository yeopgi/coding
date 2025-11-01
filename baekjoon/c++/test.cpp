#include <iostream>

using namespace std;

int main(void)
{
    int k;
    k = 1;
    while (k < 60) {
        if (k % 4 == 0)
            printf("%d\n", k-2);    
        k++;
    }
}