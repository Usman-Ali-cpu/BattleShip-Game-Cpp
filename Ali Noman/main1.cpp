#include <iostream>
using namespace std;

class Employee
{
private:
    string name;
    double hourlyRate;
    double hoursWorked;

public:
    Employee(string name, double hourlyRate, double hoursWorked)
    {
        this->name = name;
        this->hourlyRate = hourlyRate;
        this->hoursWorked = hoursWorked;
    }

    Employee()
    {
        name = "Defualt";
        hourlyRate = 0;
        hoursWorked = 0;
    }

    string getName()
    {
        return name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    double getHourlyRate()
    {
        return hourlyRate;
    }

    void setHourlyRate(double hourlyRate)
    {
        this->hourlyRate = hourlyRate;
    }

    double getHoursWorked()
    {
        return hoursWorked;
    }

    void setHoursWorked(double hoursWorked)
    {
        this->hoursWorked = hoursWorked;
    }

    double weeklypay() const
    {
        if (hoursWorked > 40)
        {
            return hoursWorked * (1.5 * hourlyRate);
        }
        return hoursWorked * hourlyRate;
    }

    void print()
    {
        cout << "Name: " << getName() << ",\thourlyrate: " << getHourlyRate() << ",\thoursworked: " << getHoursWorked() << ",\tweekly pay: " << weeklypay() << "\n";
    }
};

int main()
{
    Employee emp1;
    Employee emp2("John", 0.9, 50);
    emp2.print();
    emp1.print();

    return 0;
}