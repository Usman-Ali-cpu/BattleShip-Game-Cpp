#include <iostream>
#include "Train.cpp"
using namespace std;

int main()
{
    Train t;
    t.addCarBack(new Car("Name1"));
    t.addCarBack(new Car("Name2"));
    t.addCarBack(new Car("Name3"));
    t.display();
    t.removeFirstCarOfType("Name2");
    t.display();
    t.deleteFirstCar();
    t.display();

    return 0;
}