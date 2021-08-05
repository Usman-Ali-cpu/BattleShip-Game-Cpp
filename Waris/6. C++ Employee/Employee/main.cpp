#include <iostream>
#include "Asg2GilbertPerez.h"
using namespace std;
 
int main()
{  

    cout << "Processing.........." << endl;
    EmployeeRoster roster;
 
    roster.add(new HourlyEmployee("Jim", "400-00-0000", 15.60, 50));
    roster.add(new SalariedEmployee("Alex", "500-00-0000", 81090, .05));
    roster.add(new SalariedEmployee("Tim", "700-00-0000", 111577, .08));
    roster.add(new HourlyEmployee("Mark", "600-00-0000", 21.75, 60));
    roster.add(new HourlyEmployee("Bill", "100-00-0000", 30.00, 45));
    roster.add(new SalariedEmployee("Bob", "200-00-0000", 61090, .02));
    roster.add(new SalariedEmployee("Joe", "300-00-0000", 31690, .1));
    roster.add(new HourlyEmployee("Jane", "700-00-0000", 25.50, 60));
    roster.add(new HourlyEmployee("Emma", "800-00-0000", 12.50, 30));
    
    cout << roster;
    return 0;
}