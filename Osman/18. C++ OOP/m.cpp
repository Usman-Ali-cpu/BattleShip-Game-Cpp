#include <iostream>
using namespace std;

class A
{
public:
    void print()
    {
        cout << "A";
    }
};
class B : public A
{
public:
    void print()
    {
        cout << "B";
    }
};

int main()
{

    B b;
    b.print();

    return 0;
}