#include <iostream>
using namespace std;

int main()
{
    int i = 5;
    int diff = 3;
    int sum = 0;
    for (int j = 1; j < 6; j++)
    {
        cout << i << ", ";
        sum += i;
        i += diff++;
    }
    cout << "\nSum of these numbers is: " << sum;

    return 0;
}