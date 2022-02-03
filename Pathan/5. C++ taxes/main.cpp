#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Enter 1. For Single status : " << endl;
    cout << "Enter 2. Married filling jointly or Qualify widow" << endl;
    cout << "Enter 3. Maried filling separatly" << endl;
    cout << "Enter status: ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        double multiAmount = 0;
        cout << "Enter amount: ";
        double amount = 0;
        double socialTax = 0;
        double medicaltax = 0;
        double takeHome = 0;
        cin >> amount;
        if (amount >= 100000 && amount < 163300)
        {
            multiAmount = 0.24 * amount;
            multiAmount -= 5920.50;
        }
        if (amount > 163300 && amount < 207350)
        {
            multiAmount = 0.32 * amount;
            multiAmount -= 18984.50;
        }
        if (amount > 207350 && amount < 518400)
        {
            multiAmount = 0.35 * amount;
            multiAmount -= 25205.00;
        }
        if (amount > 207350)
        {
            multiAmount = 0.37 * amount;
            multiAmount -= 35573.00;
        }
        if (amount <= 137700)
        {
            socialTax = 0.062 * amount;
        }
        else
        {
            socialTax = 8537.40;
        }
        medicaltax = 0.0145 * amount;
        double totalTax = socialTax + multiAmount + medicaltax;
        takeHome = amount - totalTax;

        cout << "Status: "
             << "Single" << endl;
        cout << "Income: $" << amount << endl;
        cout << "Federal Tax : $" << multiAmount << endl;
        cout << "Social Security Tax : $" << socialTax << endl;
        cout << "Medicare tax : $ " << medicaltax << endl;
        cout << "After - tax take home pay : $ " << takeHome << endl;
    }
    /* code */

    break;
    case 2:
    {
        double multiAmount;
        cout << "Enter amount: ";

        double amount = 0;
        double socialTax = 0;
        double medicaltax = 0;
        double takeHome = 0;
        cin >> amount;
        if (amount >= 100000 && amount < 171050)
        {
            multiAmount = 0.22 * amount;
            multiAmount -= 8420.00;
        }
        if (amount < 171050 && amount < 326600)
        {
            multiAmount = 0.24 * amount;
            multiAmount -= 11848.00;
        }
        if (amount > 326600 && amount < 414700)
        {
            multiAmount = 0.32 * amount;
            multiAmount -= 37969.00;
        }
        if (amount > 414700 && amount < 622050)
        {
            multiAmount = 0.35 * amount;
            multiAmount -= 50410.00;
        }
        if (amount > 622050)
        {
            multiAmount = 0.37 * amount;
            multiAmount -= 62851.00;
        }
        medicaltax = 0.0145 * amount;
        double totalTax = socialTax + multiAmount + medicaltax;
        takeHome = amount - totalTax;

        cout << "Status: "
             << "Single" << endl;
        cout << "Income: $" << amount << endl;
        cout << "Federal Tax : $" << multiAmount << endl;
        cout << "Social Security Tax : $" << socialTax << endl;
        cout << "Medicare tax : $ " << medicaltax << endl;
        cout << "After - tax take home pay : $ " << takeHome << endl;
    }
    break;
    case 3:
    {
        double multiAmount;
        cout << "Enter amount: ";

        double amount = 0;
        double socialTax = 0;
        double medicaltax = 0;
        double takeHome = 0;
        cin >> amount;
        if (amount >= 100000 && amount < 163300)
        {
            multiAmount = 0.24 * amount;
            multiAmount -= 5920.50;
        }
        if (amount > 163300 && amount < 207350)
        {
            multiAmount = 0.32 * amount;
            multiAmount -= 18984.50;
        }
        if (amount > 207350 && amount < 311025)
        {
            multiAmount = 0.35 * amount;
            multiAmount -= 25205.00;
        }
        if (amount > 311025)
        {
            multiAmount = 0.37 * amount;
            multiAmount -= 31425.50;
        }
        medicaltax = 0.0145 * amount;
        double totalTax = socialTax + multiAmount + medicaltax;
        takeHome = amount - totalTax;

        cout << "Status: "
             << "Single" << endl;
        cout << "Income: $" << amount << endl;
        cout << "Federal Tax : $" << multiAmount << endl;
        cout << "Social Security Tax : $" << socialTax << endl;
        cout << "Medicare tax : $ " << medicaltax << endl;
        cout << "After - tax take home pay : $ " << takeHome << endl;
    }
    break;

    default:
        cout << "Invalid choice !" << endl;
        break;
    }
    return 0;
}