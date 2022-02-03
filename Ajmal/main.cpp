#include <iostream>
#include "Card.h"
using namespace std;

int main()
{
    Card c1("club", "5");     // calling constructor to make object of first card
    Card c2("diamond", "10"); // calling constructor to make object of second card
    Card c3("club", "King");  // calling constructor to make object of third card
    Card c4("spade", "King"); // calling constructor to make object of fourth card
    Card c5("heart", "Jack"); // calling constructor to make object of fifth card
    c1.print();               // print data of card 1
    cout << endl;
    c2.print(); // print data of card 2
    cout << endl;

    c3.print(); // print data of card 3
    cout << endl;
    c4.print(); // print data of card 4
    cout << endl;
    c5.print(); // print data of card 5
    cout << endl;
    cout << "\nFirst Equility Test: ";
    if (c1.isEqualSuits(c2)) // check wether two card's suits are eqaul or not
    {                        // print this if they are equal
        cout << "(";
        c1.print();
        cout << ")\t is equal to \t(";
        c2.print();
        cout << ") by suit " << endl;
    }
    else
    { // print this if they are not equal
        cout << "(";
        c1.print();
        cout << ")\t    is not equal to \t(";
        c2.print();
        cout << ") by suit " << endl;
    }
    cout << "Second Equility Test: ";
    if (c3.isEqualValue(c4)) // check wether two card's value are equal or not
    {                        // print this if they are  equal
        cout << "(";
        c3.print();
        cout << ")\t is equal to \t(";
        c4.print();
        cout << ") by value " << endl;
    }
    else
    { // print this if they are not equal
        cout << "(";
        c3.print();
        cout << ")\t is equal not to \t(";
        c4.print();
        cout << ") by value " << endl;
    }
    cout << "Third Greater Than Test: ";
    if (c4.isGreaterValue(c2)) // check wether value of card is greater than other card or not
    {                          // print this if value of card is greater
        cout << "(";
        c4.print();
        cout << ")\t is Greater than \t(";
        c2.print();
        cout << ") by value " << endl;
    }
    else
    { // print this if value of card is not greater
        cout << "(";
        c4.print();
        cout << ")\t is not Greater than \t(";
        c2.print();
        cout << ") by value " << endl;
    }
    cout << "Fourth Less Than Test: ";
    if (c1.isGreaterValue(c5)) // check wether value of card is less than other card or not
    {                          // print this if value of card is less
        cout << "(";
        c1.print();
        cout << ")\t is Less than \t(";
        c5.print();
        cout << ") by value " << endl;
    }
    else
    { // print this if value of card is not less
        cout << "(";
        c1.print();
        cout << ")\t is not Less than \t(";
        c5.print();
        cout << ") by value " << endl;
    }

    return 0;
}