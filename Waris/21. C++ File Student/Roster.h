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
    Roster(Student arr[], int size);
    Roster();
    void addStudent(Student st);
    void display();
    void displayAverageDays();
    void displayDegree(string degree);
    void displayID(int id);
    void inValidEmails();
};
#endif