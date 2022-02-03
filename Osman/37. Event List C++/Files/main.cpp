#include <iostream>
#include "Event.h"
#include "Node.h"
#include "Eventlist.h"

using namespace std;

int main()
{
    EventList eventlist;

    while (true)
    {
        int choice;
        cout << "Enter 1. To Exit" << endl;
        cout << "Enter 2. To Append Event" << endl;
        cout << "Enter 3. To Display Along With Time Elapsed" << endl;
        cout << "Enter 4. To Display Untill Time Elasped" << endl;
        cout << "Enter 5. To Find Event " << endl;
        cout << "Enter 6. To Insert Event After Location" << endl;
        cout << "Enter 7. To Insert Event Before Location" << endl;
        cout << "Enter 8. To Clear Event List" << endl;
        cout << "Enter 9. To Get Length" << endl;
        cout << "Enter 10. To Remove Event" << endl;
        cout << "Enter 11. To Load File" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            exit(0);
            break;
        case 2:
        {
            string name;
            int time;
            cout << "Enter Event Name : ";
            cin >> name;
            cout << "Enter Time Elapsed:  ";
            cin >> time;
            Event e(time, name);
            eventlist.append(e);
        }

        break;
        case 3:
        {

            cout << endl;
            eventlist.display();
            cout << endl;
        }
        break;
        case 4:
        {
            int time;
            cout << "Enter time elapsed to display events until that time : ";
            cin >> time;
            cout << endl;
            eventlist.displayUntil(time);
            cout << endl;
        }
        break;
        case 5:
        {
            string name;
            int time;
            cout << "Enter Event Name : ";
            cin >> name;
            cout << "Enter Time Elapsed:  ";
            cin >> time;
            Event e(time, name);
            cout << endl;
            eventlist.find(e);
            cout << endl;
        }
        break;
        case 6:
        {
            string loc;
            cout << "Enter Location Event Name To insert After : ";
            cin >> loc;
            string name;
            int time;
            cout << "Enter Event Name : ";
            cin >> name;
            cout << "Enter Time Elapsed:  ";
            cin >> time;
            Event e(time, name);
            cout << endl;
            eventlist.insertAfter(loc, e);
            cout << "\n************* INSERTING ******************" << endl;
            cout << "Inserted Successfully " << endl;
            cout << "\n************* ********** ******************" << endl;
        }
        break;
        case 7:
        {
            string loc;
            cout << "Enter Location Event Name To insert before : ";
            cin >> loc;
            string name;
            int time;
            cout << "Enter Event Name : ";
            cin >> name;
            cout << "Enter Time Elapsed:  ";
            cin >> time;
            Event e(time, name);
            cout << endl;
            eventlist.insertBefore(loc, e);
            cout << "\n************* INSERTING ******************" << endl;
            cout << "Inserted Successfully " << endl;
            cout << "\n************* ********** ******************" << endl;
        }
        break;
        case 8:
        {
            cout << "\n************* CLEARED ******************" << endl;
            eventlist.clear();
            cout << "\n************* ******** ******************" << endl;
        }
        break;
        case 9:
        {
            cout << "\n************* LENGTH ******************" << endl;
            cout << "Length of Event List is : " << eventlist.getLength() << endl;
            cout << "\n************* ******* ******************" << endl;
        }
        break;
        case 10:
        {
            string name;
            int time;
            cout << "Enter Event Name To Remove: ";
            cin >> name;
            cout << "Enter Time Elapsed To Remove:  ";
            cin >> time;
            Event e(time, name);
            cout << "\n************* REMOVING ******************" << endl;
            eventlist.remove(e);
            cout << "REMOVED Successfully " << endl;
            cout << "\n************* ********** ******************" << endl;
        }
        break;
        case 11:
        {
            eventlist.loadFile();
        }
        break;

        default:
            cout << "Invalid Input !" << endl;
            break;
        }
    }

    return 0;
}