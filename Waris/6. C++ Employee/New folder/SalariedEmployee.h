#pragma once
#ifndef SalariedEmployee_H
#define SalariedEmployee_H

#include<iomanip>
#include "Employee.h"
#include<sstream>
using namespace std;

class SalariedEmployee : public Employee {
	double yearlySal;
	double bonusRate;
public:
	SalariedEmployee(string name, string ssn, double ys, double br) {
		setName(name);
		setSSN(ssn);
		yearlySal = ys;
		bonusRate = br;
	}
	void setYearlySal(double yr) {
		yearlySal = yr;
	}
	void setBonusRate(double br) {
		bonusRate = br;
	}
	double getYearlySal() {
		return yearlySal;
	}
 	double getBonusRate() {
		return bonusRate;
	}

	double calBonusAmount() {
		return yearlySal * bonusRate;
	}
	double getCalculatedSalary() {
		return calBonusAmount() + yearlySal;
	}
	string toString() {
        ostringstream sObject;
        sObject << std::fixed;
        sObject << std::setw(5);
        sObject << std::setprecision(2);
        sObject << bonusRate;
        string brate = sObject.str();

        ostringstream aObject;
        aObject << std::fixed;
        sObject << std::setw(10);
        aObject << std::setprecision(2);
        aObject <<calBonusAmount();
        string btime = aObject.str();

        ostringstream bObject;
        bObject << std::fixed;
        sObject << std::setw(10);
        bObject << std::setprecision(2);
        bObject<< yearlySal;
        string ySal = bObject.str();

        ostringstream cObject;
        cObject << std::fixed;
        sObject << std::setw(10);
        cObject << std::setprecision(2);
        cObject<< getCalculatedSalary();
        string calSal = cObject.str();

        
        
		return ( "Name: " + getName() + "\tSSN: " + getSSN() + "\tBonus Rate: " + brate + "\tSalary: $"
			+ ySal + "\tBonus Amount: $" + btime
			+ "\t\tTotal salary: $" + calSal);
	}
};
#endif