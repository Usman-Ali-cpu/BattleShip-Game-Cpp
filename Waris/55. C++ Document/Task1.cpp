#include <iostream>
using namespace std;

double purchase()
{
    cout << "Enter 1. For P3 processor" << endl;
    cout << "Enter 2. For P5 processor" << endl;
    cout << "Enter 3. For P7 processor" << endl;
    cout << "Select Processor : ";
    double estimatedcost = 0;
    int processorChoice;
    int processorPrice = 0;
    cin >> processorChoice;
    switch (processorChoice)
    {
    case 1:
        processorPrice = 100;
        break;
    case 2:
        processorPrice = 120;
        break;
    case 3:
        processorPrice = 200;
        break;
    default:
        cout << "Invalid choice!";
        break;
    }

    cout << "Enter 1. For 16 GB ram" << endl;
    cout << "Enter 2. For 32 GB ram" << endl;
    cout << "Select RAM : ";
    int ramchoice;
    int ramprice = 0;
    cin >> ramchoice;
    switch (ramchoice)
    {
    case 1:
        ramprice = 75;
        break;
    case 2:
        ramprice = 150;
        break;
    default:
        cout << "Invalid choice!";
        break;
    }

    cout << "Enter 1. For 1 TB Storage" << endl;
    cout << "Enter 2. For 2 TB Storage" << endl;
    cout << "Select Storage : ";
    int storagechoice;
    int storageprice = 0;
    cin >> storagechoice;
    switch (storagechoice)
    {
    case 1:
        storageprice = 50;
        break;
    case 2:
        storageprice = 100;
        break;
    default:
        cout << "Invalid choice!";
        break;
    }

    cout << "Enter 1. For 19 \" Screen" << endl;
    cout << "Enter 2. For 23 \" Screen" << endl;
    cout << "Select Screen : ";
    int screenchoice;
    int screenprice = 0;
    cin >> screenchoice;
    switch (screenchoice)
    {
    case 1:
        screenprice = 65;
        break;
    case 2:
        screenprice = 120;
        break;
    default:
        cout << "Invalid choice!";
        break;
    }

    cout << "Enter 1. For Mini Tower Case" << endl;
    cout << "Enter 2. For Midi Tower Case" << endl;
    cout << "Select Case : ";
    int casechoice;
    int caseprice = 0;
    cin >> casechoice;
    switch (casechoice)
    {
    case 1:
        caseprice = 40;
        break;
    case 2:
        caseprice = 70;
        break;
    default:
        cout << "Invalid choice!";
        break;
    }
    cout << "Enter 1. For 2 USB ports" << endl;
    cout << "Enter 2. For 4 USB ports" << endl;
    cout << "Select USB ports : ";
    int portchoice;
    int portprice = 0;
    cin >> portchoice;
    switch (portchoice)
    {
    case 1:
        portprice = 10;
        break;
    case 2:
        portprice = 20;
        break;
    default:
        cout << "Invalid choice!";
        break;
    }
    estimatedcost = processorPrice + ramprice + storageprice + screenprice + caseprice + portprice;
    double cost = 0.2 * estimatedcost;
    estimatedcost = cost + estimatedcost;
    return estimatedcost;
}
bool esimateBudget(double estimate, double current)
{
    if (estimate > current)
    {
        cout << "Price is not in your Budget" << endl;
        cout << "Kindly reduce the cost" << endl;
        return false;
    }
    return true;
}

int main()
{
    double currentbudget;
    cout << "Enter your budget : ";
    cin >> currentbudget;
    double estimateCost = purchase();
    cout << "\n***********************************************\n";
    cout << "Total estimated cost : " << estimateCost << endl;
    cout << "Total Current Budget : " << currentbudget << endl;
    cout << "******************************************************" << endl;

    while (!esimateBudget(estimateCost, currentbudget))
    {
        estimateCost = purchase();
        cout << "\n***********************************************\n";
        cout << "Total estimated cost : " << estimateCost << endl;
        cout << "Total current cost : " << currentbudget << endl;
        cout << "******************************************************" << endl;
    }

    return 0;
}