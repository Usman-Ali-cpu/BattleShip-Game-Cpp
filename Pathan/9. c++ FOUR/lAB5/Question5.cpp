#include <iostream>
using namespace std;

int main()
{
    int choice;
    cout << "1.Task1\n2.Task2\n3.Task3\n0. Exit\n";
    cout << "Type a number 1, 2, 3 to select task: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "You select task 1";
        break;
    case 2:
        cout << "You select task 2";
        break;
    case 3:
        cout << "You select task 3";
        break;
    case 0:
        cout << "You select EXIT";
        break;
    default:
        cout << "Invalid number";
        break;
    }

    return 0;
}