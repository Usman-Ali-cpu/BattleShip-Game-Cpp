#include <iostream>
using namespace std;

int removelasttwo_digit(int n)
{
    for (int i = 0; i < 2; i++)
    {
        n = n / 10;
    }
    return n;
}

int removefirsttwo_digit(int n)
{
    int rem = 0;
    int total = 0;
    while (n > 99)
    {
        rem = n % 10;
        total = (total * 10) + rem;
        n = n / 10;
    }
    int remainder = 0;
    int reversedNumber = 0;
    while (total != 0)
    {
        remainder = total % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        total /= 10;
    }
    return reversedNumber;
}
int main()
{
    int n = 3455;
    cout << "Enter a number : ";
    cin >> n;
    if (n < 99)
    {
        cout << "The number " << n << " is too small";
    }
    else
    {
        int n1 = removelasttwo_digit(n);
        int n2 = removefirsttwo_digit(n);
        if (n1 > n2)
        {
            cout << "Such a number is " << n1 << endl;
        }
        if (n2 > n1)
        {
            cout << "Such a number is " << n2 << endl;
        }
        if (n1 == n2)
        {
            cout << "Both are equal" << endl;
        }
    }

    return 0;
}