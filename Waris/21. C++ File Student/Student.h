#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Student
{
private:
    string ID;
    string firstName;
    string lastName;
    string emialAddress;
    int age;
    int *arr;
    string degree;

public:
    Student(string ID, string firstName, string lastName, string emialAddress, int age, int arr[], string degree);
    Student();
    Student(string line);
    void print();
    string getDegree();
    int getID();
    void averageDays();
    string getEmail();
};
#endif