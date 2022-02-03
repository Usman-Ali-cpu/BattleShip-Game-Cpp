#include <iostream>
using namespace std;
#include <string>

class Automobile
{
protected:
    char city[21];   // current location (city) of a Automobile
    char street[31]; // current location (street) of a Automobile
    int capacity;    // the capacity of a Automobile
public:
    Automobile(const char *city, const char *street, int capa) // three parameter constructor
    {
        this->capacity = capa;
        strncpy(this->city, city, 21);     // assigning to char array city
        strncpy(this->street, street, 31); // assigning to char array street
    }
};

class Taxi : public Automobile
{
    bool ePayment; // availability of WiFi service
public:
    Taxi(const char *city, const char *street, int capa, bool pay) : Automobile(city, street, capa)
    {
        this->ePayment = pay;
    }
};

// Implement a) the three-argument Automobile constructor and b) the four-argument Taxi constructor.
// Include a comment where a safe empty state is coded. You should use strncpy wherever applicable.
// (No inline coding please.)