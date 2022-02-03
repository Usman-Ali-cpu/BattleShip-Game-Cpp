#include <iostream>
using namespace std;

/*
Implement the class such that a Drone object may be assigned to another Drone object correctly.

    Include a comment about the scope of your implementation (i.e. inside or outside the class).



ii) Write down a line of C++ code such that a Drone object cannot be used to initialize  a new Drone

      object. Include a comment about the scope of this line of code (i.e. inside or outside the class).


*/
struct Propeller
{

    double size;

    char engineType[16];
};

class Drone
{

    Propeller *propllers;

    int numOfPropellers;

public:
    Drone &operator=(const Drone &D)
    {
        this->numOfPropellers = D.numOfPropellers;        // assinging number of propellers
        this->propllers = new Propeller[numOfPropellers]; // creating dynamoc array
        for (int i = 0; i < numOfPropellers; i++)         // looping through number of propellers
        {
            propllers[i] = D.propllers[i]; // assigning value
        }
        return *this; // return current object
    }
};

int main()
{
    Drone d;
    Drone c = d;

    return 0;
}