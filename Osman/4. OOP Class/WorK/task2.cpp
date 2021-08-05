//2.	Linked lists                    

//2.1)  Comment the syntax of the printed lines in row 24, 27, 30, 39, 42, 45 and 48
//
//2.2)  Define the class Employee with the required data members, which are needed for a linked list (matching the class ListOfEmployees).
// 
#include <iostream>
#include <string>
using namespace std;


class Employee
{
private:                                                 //Private attributes
    Employee* next;
    string surname,firstname;

public:                                                  //Public attributes
    Employee()                                           //Constructor of the employee
    {
        surname = "Unkown";
        firstname = "Unkown";
        next = NULL;
    }
    // Getters and setters for the private attributes
    string get_surname ()               
    {
        return surname;
    }
    string get_firstname ()
    {
        return firstname;
    }

    Employee *get_next ()
    {
        return next;
    }


    void  set_surname (string s)               
    {
        surname = s;
    }
    void set_firstname (string f)
    {
        firstname = f;
    }

    void set_next (Employee * t)
    {
        next = t;
    }
    void show(){
        cout<< "First Name : " << get_firstname() << endl;
        cout<< "Sur Name : " << get_surname() << endl;
    }
};

class ListOfEmployees
{
private:
    Employee *Head;                     // Top of the list
public:
    ListOfEmployees():Head(0) {}        // Constructor to initiated the top of the list
                                            // initialized with null

    void insert(Employee *t)            // Using the member function to insert the new employees
    {                                   // inserting new employee t
        if(Head == NULL){
            Head = t;
        }
        else {
            Employee *temp = Head;
            while(temp->get_next() != NULL){
                temp = temp->get_next();
            }
            temp->set_next(t);
        }
    }
    void show(){
        Employee *temp = Head;
        int i =0;
        while(temp != NULL){
            cout<< "Enployee " << i+1<< " -> " << endl;
            temp->show();
            temp = temp->get_next();
        }
    }
   
};





int main()
{
    ListOfEmployees emplist;
    while(true)
    {
        cout<< "\n******************\n";
        cout<< "Enter 1 for Insert"<<endl;
        cout<< "Enter 2 for Show"<< endl;
        cout<< "Enter 3 to Exit" << endl;
        cout<< "\n******************\n";
        int c ;
        cout<< "Enter Choice : ";
        cin >> c;

        switch (c)
        {
        case 1:
            {
                Employee * t = new Employee();
                string first;
                string second;
                cout<< "Please introduce your Firstname : ";
                cin >> first;
                cout<< "Please introduce your surname : ";
                cin >> second;

                t->set_surname(second);
                t->set_firstname(first);
                emplist.insert(t);
            }
            break;
        case 2:
            emplist.show();
            break;
        case 3:
            exit(0);
            break;
        
        default:
        cout<< "Invalid Choice !"<< endl;
            break;
        }
    }

    return 0;
}