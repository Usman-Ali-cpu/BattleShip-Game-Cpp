#include <iostream>
using namespace std;
const double PRECISION = 1e-10;

double inputDouble(string input)
{
    cout << "Please enter " << input << ": ";
    double value;
    cin >> value;
    return value;
}

int main()
{
    double val = inputDouble("a value ");
    cout << "InputDouble returned " << val << endl;

    return 0;
}