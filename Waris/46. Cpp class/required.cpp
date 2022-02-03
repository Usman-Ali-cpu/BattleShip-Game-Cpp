#include <iostream>
#include <vector>
#include "required.h"
using namespace std;

Students::Students()
{
    name = "";
    emailaddress = "";
    gpa = 0;
}
Students::Students(string n, string email, double g)
{
    name = n;
    emailaddress = email;
    gpa = g;
}
void Students::print()
{
    cout << "Student Name : " << name << endl;
    cout << "Student Email address : " << emailaddress << endl;
    cout << "Student GPA : " << gpa << endl;
}
Teachers::Teachers()
{
    name = "";
    emailaddress = "";
    salary = 0;
}
Teachers::Teachers(string n, string email, double sal)
{
    name = n;
    emailaddress = email;
    salary = sal;
}
void Teachers::print()
{
    cout << "Teacher Name : " << name << endl;
    cout << "Teacher Email address : " << emailaddress << endl;
    cout << "Teacher Salary : " << salary << endl;
}

Course::Course()
{
    name = "";
    description = "";
}
Course::Course(string n, string d)
{
    name = n;
    description = d;
}
void Course::print()
{
    cout << "Course Name : " << name << endl;
    cout << "Description : " << description << endl;
}

CourseSection::CourseSection()
{
}
CourseSection::CourseSection(Course course, vector<Students> list)
{
    courseName = course;
    st = list;
}
void CourseSection::addStudent(Students s)
{
    st.push_back(s);
}
void CourseSection::print()
{
    courseName.print();
    for (int i = 0; i < st.size(); i++)
    {
        st.at(i).print();
    }
}