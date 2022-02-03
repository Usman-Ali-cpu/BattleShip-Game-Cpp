
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isLower(char ch) // function to check if character is lower case or not
{
    if (ch >= 'a' && ch <= 'z')
    {
        return true;
    }
    return false;
}
bool isValid(string str) // function to check if the string is valid or not
{
    for (int i = 0; i < str.length(); i++) // loop through whole string
    {
        if (!isLower(str.at(i))) // check if have any invalid character
        {
            return false; // return false, to determine it is ivvalid string
        }
    }
    return true; // else return true;
}

int main()
{
    string str;             // declare string to take input
    vector<char> character; // vector to push characters
    vector<int> numChar;    // vector of type int to push occurance of character

    cout << "Enter the data to be compressed: ";
    cin >> str;        // input string
    if (!isValid(str)) // to check if it is valid or not
    {
        cout << "The compressed data is: "
             << "invalid input"; // error message
        return 0;                // end the program
    }
    else
    {                                          // if string is valid
        for (int i = 0; i < str.length(); i++) // loop through the string
        {
            int j = 1; // to take count of character

            while (str[i] == str[i + 1] && i < str.length() - 1) // see while other character not found and reach end of string
            {
                j++; // increment count
                i++; // increment to go to next character
            }
            character.push_back(str[i]); // push character
            numChar.push_back(j);        // push count of character
        }
    }
    cout << "The compressed data is: "; // display string
    for (int i = 0; i < character.size(); i++)
    {
        cout << numChar.at(i) << character.at(i); // print charcter and it's count
    }

    return 0;
}