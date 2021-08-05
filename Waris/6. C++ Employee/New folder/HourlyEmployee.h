#pragma once
#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H
#include<iomanip>
#include "Employee.h"
#include<sstream>
using namespace std;




class HourlyEmployee : public Employee {
	double hourlyRate;
	double hoursWorked;
public:
	HourlyEmployee(string name, string ssn, double hr,double hw) {
		setName(name);
		setSSN(ssn);
		hourlyRate = hr;
		hoursWorked = hw;
	}
	void setHourlyRate(double hr) {
		hourlyRate = hr;
	}
	void setHoursWorked(double hw) {
		hoursWorked = hw;
	}
	double getHourlyRate() {
		return hourlyRate;
	}
	double getHoursWorked() {
		return hoursWorked;
	}

	double calOvertimeAmount() {
		double amount = 0.0;
		if (hoursWorked > 40)
			amount = (hoursWorked - 40) * 1.5 * hourlyRate;
		return amount;
	}
	double getCalculatedSalary() {
		double sal;
		if (hoursWorked > 40)
			sal = calOvertimeAmount()+ hourlyRate * 40;
		else
			sal = hourlyRate * hoursWorked;
		return sal;
	}
	string toString() {
        ostringstream sObject;
        sObject << std::fixed;
        sObject << std::setw(5);
        sObject << std::setprecision(2);
        sObject << hourlyRate;
        string hrate = sObject.str();

        ostringstream aObject;
        aObject << std::fixed;
        sObject << std::setw(10);
        aObject << std::setprecision(2);
        aObject <<calOvertimeAmount();
        string overtime = aObject.str();

        ostringstream bObject;
        bObject << std::fixed;
        sObject << std::setw(10);
        bObject << std::setprecision(2);
        bObject<< hoursWorked;
        string workhour = bObject.str();

        ostringstream cObject;
        cObject << std::fixed;
        sObject << std::setw(10);
        cObject << std::setprecision(2);
        cObject<< getCalculatedSalary();
        string calSal = cObject.str();

        
		return ("Name: " + getName() + "\tSSN: " + getSSN() + "\tHourly Rate: $" + hrate + "\tHours : "
			+ workhour + "\t\tOvertime Amt: $" + overtime
			+ "\t\tTotal salary: $" + calSal);
	}
};
#endif