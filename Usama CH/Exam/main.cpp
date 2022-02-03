#include <iostream>
using namespace std;

int main()
{
    string str;                            // to store input from user
    cout << "Enter input: ";               // asking for input
    cin >> str;                            // input a string
    int output = 0;                        // to display output on console
    int current = 0;                       // store a single char and cast to int
    char prev;                             // to store operator
    for (int i = 0; i < str.length(); i++) // loop through whole string
    {

        if (isdigit(str[i])) // check if char is digit
        {
            int num = str[i] - 48; // cast it into int
            if (prev == '-')       // check if operator is -
            {
                output -= num; // subtract it from output
            }
            else if (prev == '+') // check if operator is +
            {
                output += num; // add it to output
            }
            else
            {
                output = num; // if it is start
            }
        }
        else
        {
            prev = str[i]; // store operator
        }
    }
    cout << output; // output on console

    return 0;
}