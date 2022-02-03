#pragma once
#ifndef FREQUENT_FLYER_ACCOUNT_H
#define FREQUENT_FLYER_ACCOUNT_H

class FrequentFlyerAccount
{
    string mName;    //  member for holding name
    double mBalance; // member for balance

public:
    FrequentFlyerAccount(string name); // parameterize constructor
    double getBalance();               // balance getter
    string getName();                  // name getter
    //  addFlightToAccount return true when the names match and return false otherwise
    bool addFlightToAccount(PlaneFlight flight); // add flight

    bool canEarnFreeFlight(double mileage); // check if it can earn free flight or not
    // freeFlight return true when enough of a mileage balance existed to create a free flight and return false otherwise
    bool freeFlight(string from, string to, double mileage, PlaneFlight &flight); // give free flight
};

#endif