#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
using namespace std;


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
