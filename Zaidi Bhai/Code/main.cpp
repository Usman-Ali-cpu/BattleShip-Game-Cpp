#include <iostream>
#include "Linked_List.cpp" // include implementation file
// if getting error on your compiler then ("#include "Linked_List.h")

using namespace std;

int main()
{
    cout << "/******************************************************" << endl;
    cout << "** Program : linked_list.cpp" << endl;
    cout << "** Author : Your Name" << endl;
    cout << "** Date : 8 / 12 / 2021 " << endl;
    cout << "******************************************************/\n"
         << endl;

    Linked_List li; // declare li of type Linked_list
    while (true)
    {
        unsigned int num;
        cout << "Please enter a number: ";
        cin >> num; // prompt user to enter a number
        li.push_back(num);

        char ch; // declaring character for taking choice
        cout << "Do you want another num(y or n): ";
        getchar();
        cin >> ch;                     // prompt user to enter choice
        while (ch == 'Y' || ch == 'y') // loop will iterate while user enter y again and again
        {
            cout << "Enter a number: ";
            cin >> num;        // taking input integer value
            li.push_back(num); // inserting value in the list
            cout << "Do you want another num(y or n): ";
            cin >> ch; //agains prompt for a choice to enter more numbers or not
            if (ch == 'N' || ch == 'n')
            {
                break; // loop will be end if user enter N or n
            }
        }
        char order;
        getchar(); // for ignoring buffer value
        cout << "Sort ascending or descending (a or d)? ";
        cin >> order; // input choice of user for order of printing
        if (order == 'a')
        {
            li.sort_ascending(); // sort elements of list in ascending order.
        }
        else
        {
            li.sort_descending(); // sort elements of list in descending order.
        }
        cout << "Your linked list is: ";
        li.print(); // print all elements of list

        char end;
        getchar();                                                                       // for ignoring buffer value
        cout << "You have " << li.countPrime() << " prime number in your list." << endl; // output how many prime numbers are in list
        cout << "Do you want to do this again (y or n)? ";
        cin >> end; // prompt user to enter choice

        if (end == 'n' || end == 'N') // program ends when user enter n or N
        {
            return 0;
        }
        li.clear();    // clear whole list
        system("cls"); // clear console screen
    }

    return 0;
}