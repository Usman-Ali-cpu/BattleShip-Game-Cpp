

#include <iostream>
#include "String.cpp"
using namespace std;

int main()
{
    cout << "Create two strings, one using constructor, "
         << "another an initialization statement" << endl;
    String str1("MiraCosta College"); // regular constructor
    String str2 = str1;               // copy constructor

    //   Print the value of both string on the console using the print function.Change the string stored in the second String object using the change function, then print both String objects again.
    // Use the change function and print
    cout << "\nAfter changing string 2 using change() " << endl;
    str2.change("Cal State San Marcos");
    str2.print();
    cout << "\nAfter changing string 1 using change()" << endl;
    str1.change("UCSD");
    str1.print();

    return 0;
}