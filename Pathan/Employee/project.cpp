#include <iostream>
#include "EmployeeList.cpp"
#include "Employee.cpp"
using namespace std;

int main()
{
    EmployeeList<Employee> emplist;

    while (true)
    {
        cout << "Enter 1. to insert" << endl;
        cout << "Enter 2. to display" << endl;
        cout << "Enter 3. to find" << endl;
        cout << "Enter 4. to Quit" << endl;
        int choice = -1;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter name : ";
            string name;
            int id;
            cin >> name;
            cout << "Enter Id: ";
            cin >> id;
            cout << "Enter salary: ";
            double sal;
            cin >> sal;
            Employee emp;
            emp.ID = id;
            emp.name = name;
            emp.salary = sal;
            emplist.insertEnd(emp);
            cout << "The employee record was added successfully." << endl;
        }

        break;
        case 2:
        {
            cout << "The list of employees in the system are:\n"
                 << endl;
            emplist.print();
        }
        break;
        case 3:
        {
            cout << "Enter id: ";
            int id;
            cin >> id;
            cout << "FIND EMPLOYMENT INFO " << id;
            emplist.getIndex(id);
        }
        break;
        case 4:
        {
            exit(0);
        }
        break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    return 0;
}