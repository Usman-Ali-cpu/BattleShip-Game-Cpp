#include <iostream>
#include <fstream>
#include "Roster.cpp"
using namespace std;

void manipulateData(string student[])
{
    ifstream inFile("student.txt");
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
    Roster r;
    string arrSt[5];
    manipulateData(arrSt);

    // const string studentData[] =
    //     {
    //         "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
    //         "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    //         "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    //         "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    //         "A5,Name,LastName,Name@gmail.com,22,34,60,45,SOFTWARE",
    //     };

    for (int i = 0; i < 5; i++)
    {
        Student st(arrSt[i]);
        r.addStudent(st);
    }
    r.display();

    return 0;
}