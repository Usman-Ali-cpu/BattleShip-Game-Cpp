#include <iostream>
using namespace std;
int id = 1;
class Person
{
public:
    virtual void set() = 0;
    virtual void display() = 0;
};

class Staff : public Person
{
    int staffId = id++;

public:
    void display()
    {
        cout << "Staff Employee :" << staffId << endl;
    }
    void set()
    {
    }
};
class Student : public Person
{
    int studentId = id++;

public:
    void display()
    {
        cout << "Student Id :" << studentId << endl;
    }
    void set()
    {
    }
};
int main()
{
    Person *p[2] = {new Staff, new Student};
    for (int i = 0; i < 2; i++)
    {
        p[i]->display();
        delete p[i];
    }
}

// line 39
// type: making object of abstract classes
// problem: try to object of abstract classes
// fix: implement void set(){}  function in drived classes.