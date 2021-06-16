#pragma once
#ifndef DATE_H
#define DATE_H


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
    Date &operator=(const Date &other);

    void setDate(unsigned long dayNumber);

    void printDate();

    //Contract: Year, Month, Day should be valid
    //          Year should be a positive number, 
    //          month should be a number in range [1,12], 
    //          date should be a numbers in range [1,31] and valid. 
    void setDate(unsigned int year, unsigned int month, unsigned int day);

    /*                                           */
    /* YOU MAY ADD YOUR MODIFICATIONS HERE       */
    /*                                           */
    
    
private:
    /*                                           */
    /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
    /*                                           */
    unsigned int year;
    unsigned int month;
    unsigned int day;
};



#endif //COSC1076_A3_DATE_H