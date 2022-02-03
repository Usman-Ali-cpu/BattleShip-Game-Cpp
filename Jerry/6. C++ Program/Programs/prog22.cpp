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
    if (areEqual(value1, value2))
    {
        cout << "The values are Equal" << endl;
    }
    else if (areGreater(value1, value2))
    {
        cout << "The first value is greater" << endl;
    }
    else
    {
        cout << "The second value is greater" << endl;
    }
    cout << endl;

    return 0;
}