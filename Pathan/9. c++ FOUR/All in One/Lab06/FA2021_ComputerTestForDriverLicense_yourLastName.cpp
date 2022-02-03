#include <iostream>
#include <string>
using namespace std;

void displayResults(string firstname, string lastname, string SSnum, string address, string result, string missed)
{
    cout << "FA2021_DriverLicenseTest_Smith.cpp\n";
    cout << "DRIVER TEST RESULT – JAMES SMITH" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "Driver's name:\t\t\t" << firstname << ", " << lastname << endl;
    cout << "SS Number:\t\t\t" << SSnum << endl;
    cout << "Address:\t\t\t" << address << endl;
    cout << "Driver's License:\t\t12345678" << endl;
    cout << "Test date:\t\t\t11/30/2021" << endl;
    cout << "Result\t\t\t\t" << result << endl;
    cout << "Missed Questions:\t\t\t" << missed << endl;
}
void startTest(int &correctAswer, char *key, string &missed)
{
    for (int i = 0; i < 25; i++)
    {
        char a;
        cout << "Enter Answer (A, B, C, D) for Question " << i + 1 << ": ";
        cin >> a;
        if (key[i] == a)
        {
            correctAswer++;
        }
        else
        {
            missed += to_string(i + 1) + ",";
        }
    }
}
int main()
{
    cout << "Enter first name : ";
    string fname;
    cin >> fname;
    cout << "Enter last name: ";
    string lname;
    cin >> lname;
    cout << "Enter SSnumber : ";
    string ssnumber;
    cin >> ssnumber;
    cout << "Enter address : ";
    string address;
    cin >> address;
    char key[] = {'A', 'C', 'A', 'A', 'A', 'A', 'A', 'C', 'B', 'A', 'B', 'A', 'D', 'A', 'B', 'A', 'A', 'A', 'A', 'C', 'C', 'B', 'A', 'D', 'A'};
    int correctAnwer = 0;
    string missedQuestions;
    string result = "FAILED";
    if (correctAnwer >= 20)
    {
        result = "PASSED";
    }
    startTest(correctAnwer, key, missedQuestions);
    displayResults(fname, lname, ssnumber, address, result, missedQuestions);

    system("pause");
    return 0;
}