#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float x, y;
    cout << "Enter value of x : ";
    cin >> x;
    if (x >= 9)
    {
        y = sqrt(x) - 2;
    }
    if (x < 9)
    {
        y = 10 + x;
    }
    cout << "x = " << x << " the value of y is: " << y << endl;

    return 0;
}