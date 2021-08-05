#pragma once
#ifndef EmployeeRoaster_H
#define EmployeeRoaster_H


#include<iostream>
#include<iomanip>
#include<vector>
#include "Employee.h"
#include<sstream>
using namespace std;

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
