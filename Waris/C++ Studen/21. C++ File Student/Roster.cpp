#include <iostream>
#include "Student.cpp"
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
            cout << "\nStudent #" << i + 1 << " ->  " << endl;
            classRosterArray[i].print();
        }
    }
};