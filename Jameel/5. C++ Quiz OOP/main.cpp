#include <iostream>
using namespace std;

class Vehicle : public iVehicle
{
    int gas;

public:
    int consumed()
    {
        return gas;
    }
    void drive(int distance)
    {
        gas = distance;
    }
};

class iVehicle
{
public:
    virtual void drive(int distance) = 0;
};

iVehicle * v  = new Vehicle();
// int id = 1;

// class Person
// {
// public:
//     virtual void set() = 0;
//     virtual void display() = 0;
// };
// class Staff : public Person
// {
//     int staffid = id++;

// public:
//     void display()
//     {
//         cout << "Staff Employee:" << staffid << endl;
//     }
// };

// class Student : public Person
// {
//     int studentid = id++;

// public:
//     void display()
//     {
//         cout << "Student id:" << studentid << endl;
//     }
// };

int main()
{
    Person *p[2] = {new Staff, new Student};
    for (int i = 0; i < 2; i++)
    {
        p[i]->display();
        delete p[i];
    }
}