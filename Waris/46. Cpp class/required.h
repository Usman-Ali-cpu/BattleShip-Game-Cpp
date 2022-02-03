#include <iostream>
#include <vector>
using namespace std;

class Students
{
    string name;
    string emailaddress;
    double gpa;

public:
    Students();
    Students(string n, string email, double gpa);
    void print();
};
class Teachers
{
    string name;
    string emailaddress;
    double salary;

public:
    Teachers();
    Teachers(string n, string email, double sal);
    void print();
};

class Course
{
    string name;
    string description;

public:
    Course();
    Course(string n, string d);
    void print();
};

class CourseSection
{
    Course courseName;
    vector<Students> st;

public:
    CourseSection();
    CourseSection(Course course, vector<Students> list);
    void addStudent(Students s);
    void print();
};