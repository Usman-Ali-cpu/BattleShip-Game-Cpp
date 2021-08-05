

#include<iomanip>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
	string name;
	string ssn;
public:
	Employee() {
		name = "";
		ssn = "";
	}
	Employee(string n, string sn) {
		name = n;
		ssn = sn;
	}
	void setName(string n) {
		name = n;
	}
	void setSSN(string sn) {
		ssn = sn;
	}
	string getName() {
		return name;
	}
	string getSSN() {
		return ssn;
	}

	virtual string toString() = 0;
	virtual double getCalculatedSalary() = 0;

    friend bool operator==(Employee&, Employee&);
};

#endif 
bool operator==(Employee& e1, Employee& e2) {
	return (e1.ssn == e2.ssn);
}


#pragma once
#ifndef EmployeeRoaster_H
#define EmployeeRoaster_H

class EmployeeRoster {
	vector<Employee*> list;
public:
	void add(Employee* e) {
		for (Employee* emp : list) {
			if (emp->getSSN() == e->getSSN()) {
				cout << "Error, Duplicate found: " << e->getName() << " " << e->getSSN() << " was not added" << endl;
				return;
			}
		}
		list.push_back(e);
	}
	string toString() {
		string empRosterStr = "There are " + to_string(list.size()) + " Employees in the list\n";
		string str = "";
		for (Employee* emp : list) {
            str = "";
			str = emp->toString();
			empRosterStr += str + "\n";
		}
		return empRosterStr;
	}
	double getTotalSal() {
		double sal = 0.0;
		for (Employee* emp : list)
			sal += emp->getCalculatedSalary();
		return sal;
	}

	friend ostream& operator<<(ostream&, EmployeeRoster&);

};
#endif

ostream& operator<<(ostream& output, EmployeeRoster& e)
{
	output  << e.toString();
    output <<"\nTotal Salaries : " <<fixed << setprecision(2) << e.getTotalSal();
	return output;
}


#pragma once
#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H


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



#pragma once
#ifndef SalariedEmployee_H
#define SalariedEmployee_H



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