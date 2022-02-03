#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
using namespace std;

class Employee
{
public:
    string name;
    int ID;
    double salary;
    void print()
    {
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID : " << ID << endl;
        cout << "Employee Salary : " << salary << " S.R" << endl;
        cout << "------------------------------------------\n";
    }
};

#endif