// File name should be written here as comment line
#include <iostream>
using namespace std;

float fahrenheit_celsius(float fahr)
{
    float celc = (fahr - 32) * 5 / 9;
    return celc;
}
float celcuis_fahrenheit(float celc)
{
    float far = 9 / 5 * celc + 32;
    return far;
}
int main()
{
    // add the code here below this line
    int choice;
    cout << "1. Convert Fahrenheit temperature to Celsius\n2. Convert Celsius temperature to Fahrenheit \n0. Exit\n";
    cout << "Enter choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        float fahrenheit;
        cout << "Enter temperature in fahrenheit: ";
        cin >> fahrenheit;
        float celsius = fahrenheit_celsius(fahrenheit);
        cout << "File FA2021_TemperatureConverter_Smith" << endl;
        cout << "TEMPARATURE CONVERTER - James Smith" << endl;
        cout << "Fahrenheit to Celcius\n";
        cout << "-----------------------------------------" << endl;
        cout << "Faherenheit : \t" << fahrenheit << " F" << endl;
        cout << "Celsius : \t" << celsius << " C" << endl;
    }
    break;
    case 2:
    {
        float celsius;
        cout << "Enter temperature in fahrenheit: ";
        cin >> celsius;
        float fahrenheit = celcuis_fahrenheit(fahrenheit);
        cout << "File FA2021_TemperatureConverter_Smith" << endl;
        cout << "TEMPARATURE CONVERTER - James Smith" << endl;
        cout << "Fahrenheit to Celcius\n";
        cout << "-----------------------------------------" << endl;
        cout << "Celsius : \t" << celsius << " C" << endl;
        cout << "Faherenheit : \t" << fahrenheit << " F" << endl;
    }
    break;
    default:
        break;
    }

    system("pause"); // This will pause the output to read
    return 0;
}