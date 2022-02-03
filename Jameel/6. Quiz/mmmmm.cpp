#include <iostream>
using namespace std;
class dInt
{
    int *p;
    void free()
    {
        delete p;
    }

public:
    dInt(int v = 4)
    {
        p = new int(v);
        cout << "D" << *p;
    }
    dInt(const dInt &d)
    {
        p = new int(*d.p - 1);
        cout << "C" << *p;
    }
    dInt &operator=(const dInt &d)
    {
        if (this != &d)
        {
            free();
            p = new int(*d.p - 2);
            cout << "A" << *p;
        }
        return *this;
    }
    virtual ~dInt()
    {
        cout << "x" << *p;
        free();
    }
};
int main()
{
    dInt I(5), J;
    J = I;
    return 0;
}