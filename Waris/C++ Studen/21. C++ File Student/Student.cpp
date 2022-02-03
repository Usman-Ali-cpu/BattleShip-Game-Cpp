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
    Student(string ID, string firstName, string lastName, string emialAddress, int age, int arr[], string degree)
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
    Student()
    {
    }
    Student(string line)
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
    void print()
    {
        cout << "ID: " << ID << endl;
        cout << "FirstName : " << firstName << endl;
        cout << "LastName : " << lastName << endl;
        cout << "Email Address: " << emialAddress << endl;
        cout << "Age : " << age << endl;
        cout << "Days in Course : ";
        for (int i = 0; i < 3; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\nDegree : " << degree << endl;
    }
};