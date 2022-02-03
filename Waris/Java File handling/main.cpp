#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;     // ask for a number from user
    while (num < 2) // check while entered number is less than 2
    {
        cout << "The number must be > 2" << endl;
        cout << "Enter a positive integer: ";
        cin >> num; // again ask for a number
    }
    cout << "The non-trivial divisors are: [";
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0) // check if number (i) is divisor
        {
            cout << i << " "; // print number
        }
    }
    cout << "]";
    return 0; // terminate program
}