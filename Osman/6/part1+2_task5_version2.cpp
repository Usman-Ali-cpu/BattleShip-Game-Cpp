

// 5.   Linked lists                (20 points)
//
// 5.1  Add the data members in the class Employee, which are required for a linked list (suitable for the class ListOfEmployees).
//
// 5.2  Add the following to the class Employee:
//      a) Default constructor
//      b) Parameterized constructor with member initialization list
//      c) Member function "data_output" for outputting all employee data
//
// 5.3  In the main function, 3 employee objects have to be added to the list.
//      Output the employee data from the list using a for loop.
//      Extend the program by the member functions, which are required for this.

#include <iostream>
using namespace std;

class Employee
{
public:                                                 //Private attributes
    Employee* successor;
    string name;
    string birthYear;
    //Public attributes
    Employee()                                           //Constructor of the employee
    {
        name = "Unkown";
        birthYear = "Unkown";
        successor= NULL;
    }

};

class ListOfEmployees{
private:
    Employee *Head;
public:
    ListOfEmployees():Head(0){};
    void insert (Employee *t) {
        string empname;
        string year;
        cout << "Employee name: ";
        cin>> empname;
        cout << endl << "Year of birth: ";
        cin >> year;
        t->name = empname;
        t->birthYear = year;
        if(Head == NULL){
            Head = t;
        }
        else {
            Employee *temp = Head;
            while(temp->successor != NULL){
                temp = temp->successor;
            }
            temp->successor = t;
        }
    }
    void data_output(){
        Employee *temp = Head;
        int i =0;
        while(temp != NULL){
            cout<< "Enployee " << i+1<< " -> " << endl;
            cout<< "Name : "<< temp->name<< endl;
            cout<< "Birthday : "<< temp->birthYear<< endl;
            temp = temp->successor;
        }
    }


};

int main()
{
    ListOfEmployees emplist;
        
    Employee * t = new Employee();
    Employee * t1 = new Employee();
    Employee * t2 = new Employee();
    emplist.insert(t);
    emplist.insert(t2);
    emplist.insert(t1);
    emplist.data_output();
        
        
        
    




    return 0;
}
