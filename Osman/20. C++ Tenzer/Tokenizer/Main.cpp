/*
    Student Name: John Smith
    Student NetID: jjjs123
    Compiler Used: Visual Studio
    Program Description:
    This program reads integer, double and string from a string into vectors of int double and string.
    After reading print on the console. 
*/

#include <iostream>
#include <sstream>
#include <vector>
#include "Tokenizer.h"
using namespace std;

int main()
{

    string str = "12 34.6 length and width of rectangle with 415.2 area";
    Tokenizer t(str); // calling parameterize constructor
    cout << "Doubles : ";
    vector<double> readDouble = t.readDoubles(); // read double from string into vector of double
    for (int i = 0; i < readDouble.size(); i++)
    {
        cout << readDouble.at(i) << " ";
    }
    cout << endl;
    cout << "Integers: ";
    vector<int> readInteger = t.readIntegers(); // read integer from string into vector of int
    for (int i = 0; i < readInteger.size(); i++)
    {
        cout << readInteger.at(i) << " ";
    }
    cout << endl;
    cout << "String : ";
    vector<string> readStr = t.readString(); // read strings from string into vector of string
    for (int i = 0; i < readStr.size(); i++)
    {
        cout << readStr.at(i) << " ";
    }
    cout << endl;
    t.resetString(); // resetting a string to it orignal value
    t.clearString(); // clearing string to empty
    return 0;
}
