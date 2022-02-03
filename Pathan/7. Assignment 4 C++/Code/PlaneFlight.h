#pragma once
#ifndef PLANE_FLIGHT_H
#define PLANE_FLIGHT_H

class PlaneFlight
{
private:
    double mCost;          // private member to hold cost of flight
    std::string mFromCity; // private member to hold departure city
    std::string mToCity;   // private member to hold arival city
    std::string mname;     // private member to name of passenger
    double mMileage;       // private member to mileage of flight

public:
    PlaneFlight(std::string passengerName, std::string fromCity, std::string toCity, double cost, double mileage); // parameterize constructor
    double getCost();                                                                                              // getter for cost
    void setCost(double cost);                                                                                     // setter for cost
    double getMileage();                                                                                           // getter for mileage
    void setMileage(double mileage);                                                                               // setter for mileage
    std::string getName();                                                                                         // getter for name
    void setName(std::string name);                                                                                // setter for name
    std::string getFromCity();                                                                                     // getter for fromcity
    void setFromCity(std::string from);                                                                            // setter for fromcity
    std::string getToCity();                                                                                       // getter for tocity
    void setToCity(std::string to);                                                                                // setter for to city
};

#endif