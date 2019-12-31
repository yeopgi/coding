#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string str = "abcbc";
    int num = 0;
    string str2 = "abc";
    cout << str.compare(0, 2, str2) << endl;
    return 0;
}
