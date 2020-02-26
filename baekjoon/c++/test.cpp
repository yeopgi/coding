#include <iostream>
using namespace std;

class test
{
protected:
    int tmp;
public:
    test(){
        tmp = 5;
    }
    test(int temp) : tmp(temp) {}
    void print()
    {
        cout << "hello" << endl;
    }
    virtual ~test(){}
};


class test2 : public test
{
private:
    int b;
public:
    test2(){
        
    }

    void print()
    {
        cout << "hello2" << endl;
    }

    test2(int temp) : b(temp) {
        test();
    }
};

int main(void) 
{
    int temp1 = 5;
    test2 b;
    b.print();
    return 0;
}
