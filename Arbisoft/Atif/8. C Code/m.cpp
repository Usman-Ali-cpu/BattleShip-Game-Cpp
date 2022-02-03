#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    int accountNumber, regularMinutesUsed, premiumDayMinutes, premiumNightMinutes;
    float totalBill = 0;
    char serviceCode;

    const float REGULAR_ACCOUNT_FEE = 10.00;
    const float REGULAR_RATE = 0.20;
    const float PREMIUM_ACCOUNT_FEE = 25.00;
    const float PREMIUM_DAY_RATE = 0.10;
    const float PREMIUM_NIGHT_RATE = 0.05;

    cout << "Please enter an account number and a service code: ";
    cin >> accountNumber >> serviceCode;

    switch (serviceCode)
    {
    case 'r':
    case 'R':
        cout << "Please enter the number of minutes used: ";
        cin >> regularMinutesUsed;
        if (regularMinutesUsed > 50)
        {
            totalBill = ((regularMinutesUsed - 50) * REGULAR_RATE) + REGULAR_ACCOUNT_FEE;
        }
        else
        {
            totalBill = REGULAR_ACCOUNT_FEE;
        }
        break;
    case 'p':
    case 'P':
        cout << "Please enter the number of day minutes used: ";
        cin >> premiumDayMinutes;
        cout << "Please enter the number of night minutes used: ";
        cin >> premiumNightMinutes;
        if (premiumDayMinutes > 75)
        {
            totalBill = (premiumDayMinutes - 75) * PREMIUM_DAY_RATE;
        }
        if (premiumNightMinutes > 100)
        {
            totalBill = (premiumNightMinutes - 100) * PREMIUM_NIGHT_RATE;
        }
        totalBill += PREMIUM_ACCOUNT_FEE;
        break;
    default:
        cout << "You have entered an invalid service code" << endl;
        return 1;
        break;
    }
    cout << "Your bill is: $" << totalBill << endl;

    return 0;
}