#include<iostream>
#include"String.h"
using namespace std;

int main()
{
    CString name1 = "Malik";
    CString name2;
    CString name;
    cin >> name2;
    name = name2 + name1;
    name.makeUpper();
    cout << "*****";
    cout << name1 + name2;
    cout << "*****";

    return 0;
}
