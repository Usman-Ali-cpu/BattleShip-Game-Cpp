#include <iostream>
#include "PlaneFlight.h"
using namespace std;

PlaneFlight::PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage)
{
    this->mCost = cost;          // assign the passing value cost to member variable mCost
    this->mname = passengerName; // assign the passing value passengerName to member variable mname
    this->mFromCity = fromCity;  // assign the passing value fromcity to member variable mFromCity
    this->mToCity = toCity;      // assign the passing value tocity to member variable mToCity
    this->mMileage = mileage;    // assign the passing value milage to member variable mMileage
}
double PlaneFlight::getCost()
{
    return this->mCost; // return vlaue of cost
}
void PlaneFlight::setCost(double cost)
{
    this->mCost = cost; // set the value of cost
}
double PlaneFlight::getMileage()
{
    return this->mMileage; // return vlaue of mMileage
}
void PlaneFlight::setMileage(double mileage)
{
    this->mMileage = mileage; // set the value of mMilage
}
string PlaneFlight::getName()
{
    return this->mname; // return value of mname
}
void PlaneFlight::setName(string name)
{
    this->mname = name; // set the value of mname
}
string PlaneFlight::getFromCity()
{
    return this->mFromCity; // return vlaue of mFromCity
}
void PlaneFlight::setFromCity(string from)
{
    this->mFromCity = from; // set the value of mFromCity
}
string PlaneFlight::getToCity()
{
    return mToCity; // return vlaue of mTOCity
}
void PlaneFlight::setToCity(string to)
{
    this->mToCity = to; // set the value of mToCity
}