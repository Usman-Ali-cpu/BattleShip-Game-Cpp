#pragma once
#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include "Student.h"
using namespace std;

class Roster
{
private:
    Student *classRosterArray;
    int count;

public:
    Roster(Student arr[], int size)
    {
        classRosterArray = new Student[size];
        count = 0;
        for (int i = 0; i < size; i++)
        {
            classRosterArray[i] = arr[i];
            count++;
        }
    }
    Roster()
    {
        classRosterArray = new Student[5];
        count = 0;
    }
    void addStudent(Student st)
    {
        classRosterArray[count++] = st;
    }
    void display()
    {
        for (int i = 0; i < count; i++)
        {
            classRosterArray[i].print();
        }
        cout << endl;
    }
    void displayAverageDays()
    {
        for (int i = 0; i < count; i++)
        {
            classRosterArray[i].averageDays();
        }
        cout << endl;
    }
    void displayDegree(string degree)
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
    void displayID(int id)
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
    void inValidEmails()
    {
        cout << "inValid Emails: " << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << classRosterArray[i].getEmail() << endl;
        }
        cout << endl;
    }
};
#endif