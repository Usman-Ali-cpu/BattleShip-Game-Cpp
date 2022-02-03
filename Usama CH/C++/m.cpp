#include <iostream>
using namespace std;

int find_biggest_digit(int n)
{
    int big = 0;
    while (n > 9)
    {
        int rem = n % 10;
        if (rem > big)
        {
            big = rem;
        }
        n = n / 10;
    }
    if (n > big)
    {
        return n;
    }
    return big;
}
int find_number(int a, int b, int c)
{
    int aa = find_biggest_digit(a);
    int bb = find_biggest_digit(b);
    int cc = find_biggest_digit(c);
    if (aa > bb && aa > cc)
    {
        return a;
    }
    if (bb > aa && bb > cc)
    {
        return b;
    }
    if (cc > aa && cc > bb)
    {
        return c;
    }
    return -1;
}
int main()
{
    int a = 13, b = 444, c = 1111;
    int bigdigitnumber = find_number(a, b, c);
    int bigdigit = find_biggest_digit(bigdigitnumber);
    bool check = false;
    if (bigdigitnumber == a)
    {
        int bigb = find_biggest_digit(b);
        int bigc = find_biggest_digit(c);
        if (bigb + bigc == bigdigit)
        {
            check = true;
            cout << "Such a number is " << bigdigitnumber << endl;
        }
    }
    else if (bigdigitnumber == b)
    {
        int biga = find_biggest_digit(a);
        int bigc = find_biggest_digit(c);
        if (biga + bigc == bigdigit)
        {
            check = true;
            cout << "Such a number is " << bigdigitnumber << endl;
        }
    }
    else if (bigdigitnumber == c)
    {
        int biga = find_biggest_digit(a);
        int bigb = find_biggest_digit(b);
        if (biga + bigb == bigdigit)
        {
            check = true;
            cout << "Such a number is " << bigdigitnumber << endl;
        }
    }
    if (!check)
    {
        cout << "No such number" << endl;
    }

    return 0;
}