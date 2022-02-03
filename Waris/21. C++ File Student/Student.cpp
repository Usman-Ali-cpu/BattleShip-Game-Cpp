
#include <iostream>
#include <vector>
#include <sstream>
#include "Student.h"
using namespace std;

Student::Student(string ID, string firstName, string lastName, string emialAddress, int age, int arr[], string degree)
{
    this->ID = ID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emialAddress = emialAddress;
    this->age = age;
    arr = new int[3];
    for (int i = 0; i < 4; i++)
    {
        this->arr[i] = arr[i];
    }
    this->degree = degree;
}
Student::Student()
{
}
Student::Student(string line)
{

    vector<string> v;

    stringstream ss(line);

    while (ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        v.push_back(substr);
    }
    ID = v[0];
    firstName = v[1];
    lastName = v[2];
    emialAddress = v[3];
    age = stoi(v[4]);
    arr = new int[3];
    arr[0] = stoi(v[5]);
    arr[1] = stoi(v[6]);
    arr[2] = stoi(v[7]);
    degree = v[8];
}
void Student::print()
{
    cout << "ID: " << ID[1] << "\t";
    cout << "First Name : " << firstName << "\t";
    cout << "Last Name : " << lastName << "\t";
    cout << "Age : " << age << "  ";
    cout << "daysInCourse : {";
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "}";
    cout << "  Degree Program : " << degree << endl;
}
string Student::getDegree()
{
    return degree;
}
int Student::getID()
{
    int id = int(ID[1]) - 48;
    return id;
}
void Student::averageDays()
{
    int avr = int(arr[0]) + int(arr[1]) + int(arr[2]);
    avr = avr / 3;
    cout << "Average days for Courses for Student " << ID << ": " << avr << endl;
}
string Student::getEmail()
{
    return emialAddress;
}