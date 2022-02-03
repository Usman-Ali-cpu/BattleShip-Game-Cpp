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
bool areEqual(double param1, double param2)
{
    return abs(param1 - param2) < PRECISION;
}
bool areGreater(double param1, double param2)
{
    return (param1 - param2) >= PRECISION;
}
int compare(double para1, double para2)
{
    if (areEqual(para1, para2))
    {
        return 0;
    }
    if (areGreater(para1, para2))
    {
        return 1;
    }
    return -1;
}

int main()
{
    double value1 = inputDouble("the first value ");
    double value2 = inputDouble("the second value ");
    switch (compare(value1, value2))
    {
    case -1:
        cout << "Running the first branch of code" << endl;
        break;
    case 0:
        cout << "Running the second branch of code" << endl;
        break;

    default:
        cout << "Running the first branch of code" << endl;
        break;
    }
    cout << endl;

    return 0;
}