#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{   
    string str = "baa";

    cout << str.erase(1,2) << endl;
    str.erase();
    return 0;
}