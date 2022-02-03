#include <iostream>
#include <fstream>
#include "Roster.h"
using namespace std;

void manipulateData(string student[])
{
    ifstream inFile("student.txt");
    if (!inFile)
    {
        cout << "Error: Cannot open file!" << endl;
        exit(0);
    }
    int i = 0;

    string id, firstname, lastname, email, age, day1, day2, day3, degree;
    string line;

    while (getline(inFile, line))
    {

        inFile >> id >> firstname >> lastname >> email >> age >> day1 >> day2 >> day3 >> degree;
        string st;
        st += id + "," + firstname + "," + lastname + "," + email + "," + age + "," + day1 + day2 + day3 + "," + degree;
        student[i] = st;
        i++;
    }
    inFile.close();
}
int main()
{
    cout << "SCRIPTING AND PROGRAMMMING APPLICATIONS C867" << endl;
    cout << "\t   Language Used: C++" << endl;
    cout << "\t  Student ID: #001195694" << endl;
    cout << "\tStudent Name: Jamie Huang" << endl;
    cout << "**************************************************\n";
    cout << "\nFPPP1 TASK 1: CLASS ROSTER" << endl;

    Roster r;
    string arrSt[5];
    manipulateData(arrSt);

    for (int i = 0; i < 5; i++)
    {
        Student st(arrSt[i]);
        r.addStudent(st);
    }
    r.display();

    r.inValidEmails();
    r.displayAverageDays();
    r.displayDegree("SOFTWARE");
    r.displayID(0);
    r.displayID(1);
    r.displayID(2);
    r.displayID(3);

    return 0;
}