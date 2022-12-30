#include <iostream>
#include <algorithm>
using namespace std;

int list[1001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int man; 
    cin >> man;
    for (int i = 1; i <= man; i++) {
        cin >> list[i];
    }

    sort(list, list + (man + 1));
    
    int sum = list[1];
    for (int i = 2; i <= man; i++) {
        
        list[i] = list[i] + list[i - 1];
        sum += list[i];
    }

    cout << sum;
    return 0;  
}