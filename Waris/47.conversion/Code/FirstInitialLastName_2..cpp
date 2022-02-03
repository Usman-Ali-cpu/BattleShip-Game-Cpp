#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Enter Country Name : ";
    string country;
    getline(cin, country);
    string programmer = "Programmer Name";

    cout << "\nConverter Toolkit" << endl;
    cout << "-- -- -- -- -- -- -- -- -- --" << endl;
    cout << "1. Temperature Converter\n";
    cout << "2. Distance Converter\n";
    cout << "3. Weight Converter\n";
    cout << "4. Quit" << endl;
    int choice;
    cout << "Enter choice (1-4): ";
    cin >> choice;

    if (choice < 0 && choice > 4)
    {
        cout << "Input Invalid Value " << endl;
    }
    else
    {
        switch (choice)
        {
        case 1:
        {
            float celsius;
            cout << "Enter temperature in Celsius such as (37.6) : ";
            cin >> celsius;
            float farh = (9 * celsius / 5) + 32;
            cout << "It is " << farh << " in fahrenheit" << endl;
        }

        break;
        case 2:
        {
            float km;
            cout << "Enter distance in kilometer such as (18.7) : ";
            cin >> km;
            if (km < 0)
            {
                cout << "!!! Program does not convert negative distance" << endl;
            }
            else
            {
                float mile = 0.6 * km;
                cout << "Distance in mile is " << mile << endl;
            }
        }

        /* code */
        break;
        case 3:
        {
            float kg;
            cout << "Enter weight in kilogram : ";
            cin >> kg;
            if (kg < 0)
            {
                cout << "!!! Program does not convert negative weight" << endl;
            }
            else
            {
                float pound = kg * 2.2;
                cout << "Weight in pound is " << pound << endl;
            }
        }

        /* code */
        break;
        case 4:
        {
            cout << "\nThank you for testing my program" << endl;
            cout << "PROGRAMMER : " << programmer << endl;
            cout << "CMSC140 Common Project 2" << endl;
            cout << "Due Date : "
                 << "10/15/2021" << endl;
            exit(0);
        }

        /* code */
        break;

        default:
            cout << "Input Invalid Value " << endl;
            break;
        }
        cout << country << " sounds Fun! " << endl;
    }
    cout << "\nThank you for testing my program" << endl;
    cout << "PROGRAMMER : " << programmer << endl;
    cout << "CMSC140 Common Project 2" << endl;
    cout << "Due Date : "
         << "10/15/2021" << endl;

    return 0;
}