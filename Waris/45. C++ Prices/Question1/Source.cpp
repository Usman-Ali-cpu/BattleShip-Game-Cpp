/**********************************
*                                 *
*        MID TERM EXAM            *
*                                 *
**********************************/

#include <iostream> // including for input output operation
#include <math.h>   // including for mathematical operations
#include <iomanip>  // including for formating output
using namespace std;

int main() // start main of program
{
    float price; // float type variable to take price of car
    cout << "Enter the Price : ";
    cin >> price;                           // input price
    while (price < 50.0 || price > 50000.0) // validate input with while loop
    {
        cout << "Enter the Price in Range(50.0 - 50,000.0) : "; // prompt for again input for price
        cin >> price;                                           // input price again
    }

    float tradeIn; // float type variable to take tradeIn of car
    cout << "Enter tradeIn in dollars : ";
    cin >> tradeIn;                         // input trade in
    while (tradeIn < 0 || tradeIn >= price) // validate input tradeIn by using while loop
    {
        cout << "Enter trandeIn greater than 0 and less than price: ";
        cin >> tradeIn; // again ask for tradeIn
    }

    float downPayment; // float type variable to take downpayment  of car
    cout << "Enter down payment : ";
    cin >> downPayment;                                         // input down payment
    while (downPayment < 0 || downPayment >= (price - tradeIn)) // validate input downpayment by using while loop
    {
        cout << "Enter down payment within range : ";
        cin >> downPayment; // again input down payment
    }

    float annualIntRate; // float type variable to take annual interest rate  of car
    cout << "Enter Annual Interest Rate : ";
    cin >> annualIntRate;                            // input annual interest rate
    while (annualIntRate < 0 || annualIntRate > 0.5) // validate input annualIntRate by using while loop
    {
        cout << "Enter Annual Interest Rate in the range : ";
        cin >> annualIntRate; // again input annual interest rate
    }

    float monIntRate;
    monIntRate = annualIntRate / 12.0;              // calculate month rate
    float annualIntPercent = annualIntRate * 100.0; // calculate annual interest percentage

    float loanAmt = price - downPayment - tradeIn;                                          // calculate loan amount
    int noMonth = -12;                                                                      // no of months
    float monPayment12 = (loanAmt * monIntRate) / (1.0 - pow((1.0 + monIntRate), noMonth)); // calculate months payment

    noMonth = -24;
    int monPayment24 = (loanAmt * monIntRate) / (1.0 - pow((1.0 + monIntRate), noMonth)); // calculate months payment

    noMonth = -36;
    int monPayment36 = (loanAmt * monIntRate) / (1.0 - pow((1.0 + monIntRate), noMonth)); // calculate months payment

    noMonth = -48;
    int monPayment48 = (loanAmt * monIntRate) / (1.0 - pow((1.0 + monIntRate), noMonth)); // calculate months payment

    noMonth = -60;
    int monPayment60 = (loanAmt * monIntRate) / (1.0 - pow((1.0 + monIntRate), noMonth)); // calculate months payment

    // display results
    cout << "\nHonest Dave\'s Used Cars\n"
        << endl;
    cout << "Vehicle Price : \t" << setw(6) << fixed << setprecision(2) << price << endl;        // print price
    cout << "Trade in value : \t" << setw(6) << fixed << setprecision(2) << tradeIn << endl;     // print tradein
    cout << "Down Payment : \t\t" << setw(6) << fixed << setprecision(2) << downPayment << endl; // print downpayment
    cout << "\t\t\t---------" << endl;
    cout << "Loan Amount : \t\t" << setw(6) << fixed << setprecision(2) << loanAmt << endl;                       // print loan amount
    cout << "\nAnnual Interest rate: " << setw(7) << fixed << setprecision(1) << annualIntPercent << "%" << endl; // print annual interest percentage
    cout << "\nMonthly payment options" << endl;
    cout << "12 month\t" << fixed << setprecision(2) << monPayment12 << endl; // print payment for 12 months
    cout << "24 month\t" << fixed << setprecision(2) << monPayment24 << endl; // print payment for 24 months
    cout << "36 month\t" << fixed << setprecision(2) << monPayment36 << endl; // print payment for 36 months
    cout << "48 month\t" << fixed << setprecision(2) << monPayment48 << endl; // print payment for 48 months
    cout << "60 month\t" << fixed << setprecision(2) << monPayment60 << endl; // print payment for 60 months

    return 0;
}