#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string custumerID;
    cout << "Enter customer ID : ";
    cin >> custumerID;
    string customerName;
    cout << "Enter customer name : ";
    cin >> customerName;
    float balance;
    cout << "Enter customer blanace : ";
    cin >> balance;
    ofstream MyFile("customer.txt");

    // Write to the file
    MyFile << custumerID << " - " << customerName << " - " << balance;
    MyFile.close();

    return 0;
}