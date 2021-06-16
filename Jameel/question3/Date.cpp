#include "Date.h"
#include <exception>

Date::Date():
    year(1970), month(1), day(1)
{    
}

Date::Date(unsigned int year, unsigned int month, unsigned int day):
                        year(year), month(month), day(day)
{    
}

Date::Date(const Date& other){
    year = other.year;
    month = other.month;
    day = other.day;
}

Date::Date(Date&& other){
    year = other.year;
    month = other.month;
    day = other.day;
}

Date::~Date(){
    
}

unsigned int Date::getDay(){
    return day;
}

unsigned int Date::getMonth(){
    return month;
}

unsigned int Date::getYear(){
    return year;
}


unsigned long Date::getDayNumber() const{
    unsigned long m = ((unsigned long)month + 9) % 12;
    unsigned long y = (unsigned long)year - ((unsigned long)month/10);
    return 365*y + y/4 - y/100 + y/400 
                + (m*306 + 5)/10 + ( (unsigned long)day - 1 );
}

void Date::setDate(unsigned long dayNumber){
    unsigned long y = (10000*((unsigned long)dayNumber) + 14780)/3652425;
    unsigned long ddd = (unsigned long)dayNumber 
                            - (365*y + y/4 - y/100 + y/400);
    if (ddd < 0){
        y = y - 1;
        ddd = (unsigned long)dayNumber - (365*y + y/4 - y/100 + y/400);
    }
    unsigned long mi = (100*ddd + 52)/3060;
    unsigned long mm = (mi + 2)%12 + 1;
    y = y + (mi + 2)/12;
    unsigned long dd = ddd - (mi*306 + 5)/10 + 1;

    this->day = (unsigned int)dd;
    this->month = (unsigned int)mm;
    this->year = (unsigned int)y;
}

void Date::setDate(unsigned int year, unsigned int month, unsigned int day){
    this->day = day;
    this->month = month;
    this->year = year;
}

int  Date::operator-(Date & d){
        this->day -= d.day;
        this->month -= d.month;
        this->year -= d.year;
        return this->getDayNumber();
    }
    void Date::operator+=(int){
        int n = this->getDayNumber();
        this->setDate(n);
    }
    void Date::operator++(){
        int n = this->getDayNumber();
        this->setDate(++n);
    }
    void Date::operator--(){
        int n = this->getDayNumber();
        this->setDate(--n);
    }
    unsigned int & Date::operator[](char c){
        if(c == 'd') {
            return day;
        }
        else if(c == 'm') {
            return month;
        }
        else {
            return year;
        }
        return day;
    }

    Date Date::operator-(int i){
        int n = this->getDayNumber();
        cout << n << endl;
        n = n - i;
        if(n< 0){
            n = n+i;
            return *this;
        }
        cout << n << endl;
        this->setDate(n);
        return *this;
    }
    bool Date::operator==(Date &d1){
        int n = this->getDayNumber();
        int m = d1.getDayNumber();
        if(n == m){
            return true;
        }
        return false;
    }
    bool Date::operator<(Date &d1){
        int n = this->getDayNumber();
        int m = d1.getDayNumber();
        if(n < m){
            return true;
        }
        return false;
    }

Date::Date(unsigned long dayNumber){
    Date();
    this->setDate(dayNumber);
}


/*                                           */
/* YOU MAY ADD YOUR MODIFICATIONS HERE       */
/*                                           */




