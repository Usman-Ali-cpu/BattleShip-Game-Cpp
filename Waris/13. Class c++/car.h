#ifndef CAR_H
#define Car_H
#include <iostream>
using namespace std;

class Car
{
private:
    string name;
    double maxSpeed;

public:
    Car *nextCar;

public:
    Car()
    {
        nextCar = NULL;
    }
    Car(string n)
    {
        name = n;
        nextCar = NULL;
    }
    double getMaxSpeed() const
    {
        return maxSpeed;
    }
    string getName() const
    {
        return name;
    }
    void setName(const string &s)
    {
        name = s;
    }
};

#endif