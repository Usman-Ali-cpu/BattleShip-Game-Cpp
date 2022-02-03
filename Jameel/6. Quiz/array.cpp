#include <iostream>
using namespace std;
class iVehicle
{
public:
    virtual void move() = 0;
    virtual void speed() = 0;
    virtual void display(iostream &os) const = 0;
};
class Car : public iVehicle
{
    char m_name[31];

public:
    Car(const char *name)
    {
        strcpy(m_name, name);
    }
    void move()
    {
        cout << "Move like a car" << endl;
    }
    void speed()
    {
        cout << "Speed like a car" << endl;
    }

    void display(iostream &os) const
    {
        cout << m_name << " is a car" << endl;
    }
};

class Truck : iVehicle
{
private:
    int m_speed;

public:
    void move()
    {
        cout << "Move like a car" << endl;
    }
    void speed() = 0;
    void display(iostream &os) const = 0;
};

// 1) Create the interface class iVehicle, assuming that all of its member functions are overridden by member functions of Car.
// 2) Create an abstract class named Truck publicly derived from the interface iVehicle class.
//  The Truck class will have an integer type private data member named "m_speed".
// The Truck class will only implement the move() public member function.