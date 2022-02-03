#include <iostream>
using namespace std;

class Employee
{
public:
    string name;
    Employee *supervisor;
    Employee(string name)
    {
        this->name = name;
        supervisor = NULL;
    }
    bool isAbove(Employee *ePtr) const // constant memeber function return boolean to check if employee is above or not
    {
        if (this->supervisor == NULL) // if supervisor of current employee is null means that he has no supervisor
        {
            return true; // return true
        }
        while (ePtr != NULL) // while hierarchy does not end
        {
            if (ePtr->supervisor == this) // check if employee found
            {
                return true; // return true
            }
            ePtr = ePtr->supervisor; // go to next in  hierarchy
        }
        return false; /// otherwise return false
    }
};
int main()
{
    Employee *s = new Employee("dedj");
    Employee *s3 = new Employee("second");
    s->supervisor = s3;
    Employee *s4 = new Employee("thrd");
    s3->supervisor = s4;

    if (s3->isAbove(s4))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }

    return 0;
}