#pragma once
#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date{
public:    
    
    // Constructors/DeConstructors
    Date();

    //dayNumber is the number of days since 1/3/0000 
    Date(unsigned long dayNumber);
    Date(const Date& other);
    Date(Date&& other);
    ~Date();

    //Contract: Year, Month, Day should be valid
    //          Year should be a positive number, 
    //          month should be a number in range [1,12], 
    //          date should be a numbers in range [1,31] and valid. 
    Date(unsigned int year, unsigned int month, unsigned int day);

    
    //Getters and setters
    unsigned int getDay();
    unsigned int getMonth();
    unsigned int getYear();
    unsigned long getDayNumber() const;

    void setDate(unsigned long dayNumber);

    //Contract: Year, Month, Day should be valid
    //          Year should be a positive number, 
    //          month should be a number in range [1,12], 
    //          date should be a numbers in range [1,31] and valid. 
    void setDate(unsigned int year, unsigned int month, unsigned int day);

    int operator-(Date &d);
    void operator+=(int);
    void operator++();
    void operator--();
    unsigned int &operator[](char c);
    Date operator-(int i);
    bool operator==(Date &d1);
    bool operator<(Date &d1);

    /*                                           */
    /* YOU MAY ADD YOUR MODIFICATIONS HERE       */
    /*                                           */

    friend ostream &operator<<(ostream &out, Date &p);

private:
    /*                                           */
    /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
    /*                                           */
    unsigned int year;
    unsigned int month;
    unsigned int day;
};





ostream& operator<<(ostream& out, Date& p)
{
    out << p.day << "/" << p.getMonth() << "/" << p.getYear() << std::endl;
    return out;
}
#endif //COSC1076_A3_DATE_H

