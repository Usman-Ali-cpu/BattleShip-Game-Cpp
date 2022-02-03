#include <iostream>
#include "FrequentFlyerAccount.h"
#include "PlaneFlight.h"
using namespace std;

FrequentFlyerAccount::FrequentFlyerAccount(string name) // parameterize constructor
{
    this->mName = name; // set name
    this->mBalance = 0; // intialize balance from zero
}
double FrequentFlyerAccount::getBalance()
{
    return this->mBalance; // return balance of account
}
string FrequentFlyerAccount::getName()
{
    return this->mName; // return name of account holder
}
bool FrequentFlyerAccount::addFlightToAccount(PlaneFlight flight)
{
    if (flight.getName() == this->getName()) // if name of passed flight is equal to name of account holder
    {
        this->mBalance += flight.getMileage(); // then add the mileage  to total balance of account
        return true;                           // if name is same return true
    }
    return false; // otherwise false;
}
bool FrequentFlyerAccount::canEarnFreeFlight(double mileage)
{
    if (this->mBalance >= mileage) // if blance is greater than eqaul to milage
    {
        return true;
    }
    return false;
}
bool FrequentFlyerAccount::freeFlight(string from, string to, double mileage, PlaneFlight &flight)
{
    if (this->canEarnFreeFlight(mileage)) // check if canEarn free flight
    {
        flight.setCost(0.0);         // set cost to zero for free flight
        flight.setFromCity(from);    // set from cuty
        flight.setToCity(to);        // set to city
        flight.setMileage(mileage);  // set mileage
        flight.setName(this->mName); // set name
        this->mBalance -= mileage;   // decrement balance by mileage
        return true;
    }
    return false;
}