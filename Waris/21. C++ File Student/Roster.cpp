

#include <iostream>
#include "Student.h"
#include "Roster.h"
using namespace std;

Roster::Roster(Student arr[], int size)
{
    classRosterArray = new Student[size];
    count = 0;
    for (int i = 0; i < size; i++)
    {
        classRosterArray[i] = arr[i];
        count++;
    }
}
Roster::Roster()
{
    classRosterArray = new Student[5];
    count = 0;
}
void Roster::addStudent(Student st)
{
    classRosterArray[count++] = st;
}
void Roster::display()
{
    for (int i = 0; i < count; i++)
    {
        classRosterArray[i].print();
    }
    cout << endl;
}
void Roster::displayAverageDays()
{
    for (int i = 0; i < count; i++)
    {
        classRosterArray[i].averageDays();
    }
    cout << endl;
}
void Roster::displayDegree(string degree)
{
    for (int i = 0; i < count; i++)
    {
        if (classRosterArray[i].getDegree() == degree)
        {
            classRosterArray[i].print();
        }
    }
    cout << endl;
}
void Roster::displayID(int id)
{
    for (int i = 0; i < count; i++)
    {
        if (classRosterArray[i].getID() == id)
        {
            classRosterArray[i].print();
            return;
        }
    }
    cout << "Student with this ID was not Found!" << endl;
}
void Roster::inValidEmails()
{
    cout << "inValid Emails: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << classRosterArray[i].getEmail() << endl;
    }
    cout << endl;
}
