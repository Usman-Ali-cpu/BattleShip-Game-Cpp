#include <iostream>
using namespace std;
class Device
{
public:
    virtual void power(bool On) = 0;
    virtual void display() = 0;
    virtual ~Device()
    {
    }
};
class Mobile : public Device
{
    char type = 'M';

public:
    void display()
    {
        cout << "Type :" << type << endl;
    }
    ~Mobile()
    {
    }
};
class Tv : public Device
{
    char type = 'T';

public:
    void display()
    {
        cout << "Type :" << type << endl;
    }
    ~Tv()
    {
    }
};
int main()
{
    Device **p[2] = {new Mobile(), new Tv()};
    p[0] = new Mobile();
    for (int i = 0; i < 2; i++)
    {
        p[i]->display();
        delete p[i];
    }
}

// line 15:
// line32:Device* p[2] = { new Mobile(), new Tv ()};

// line 34:p[i].display();
// can't be access with .
// fix: p[i]->display();
