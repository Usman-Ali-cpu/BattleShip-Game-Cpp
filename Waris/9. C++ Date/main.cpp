#include <iostream>
// #include<bits/stdc++.h>
using namespace std;


class Date
{
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date(){
       day = 01;
       month = 01;
       monthName = "January";
       year = 2000;
   }


   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y){
    if(m > 12 || m<1 || d != daysPerMonth(m, y) || d<=0 || d>31 || m==2){
        if(m > 12){
            this->month = 12;
        }
        else if(m <1){
            this->month = 1;
        }
        else {
            this->month = m;
        }
        if(m==2){
            if(isLeap(y)){
                if(d> 29)
                    this->day = 29;
            }
            else{
                if(d >28)
                    this->day = 28;
            }
        }
        if(d<=0){
            this->day = 1;
        }
        else if(d > daysPerMonth(m, y)){
            this->day =  daysPerMonth(m,y);
        }
        else if(d<1){
            this->day = 1;
        }
        else if(d > 31){
            this->day = 31;
        }
        else {
            this->day = d;
        }
        if(d != this->day){
            cout<< "Invalid date values: Date corrected to ";
            this->year = y;
            this->monthName = m;
            printNumeric();
            cout<< "."<< endl;
        }
        else if(m != this->month){
            cout<< "Invalid month name: the Date was set to ";
            this->year = y;
            this->monthName = m;
            printNumeric();
            cout<< "."<< endl;
        }
        
    }
    else {
        this->month = m;
        this->day = d;
    }
       this->year = y;
       monthName = name(this->month);
   }


   /* parameterized constructor: month name, day, year
 ­      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).

       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y){
       
    unsigned m = number(mn);
    if(m==0){
        cout<< "Invalid month name: the Date was set to ";
        this->day = 1;
        this->month = 1;
        this->year = 2000;
        this->monthName = "January";
        printNumeric();
        cout<< "."<< endl;
        return;
    }
    else if(m > 12 || m<1 || d > daysPerMonth(m, y) || d<=0 || d>31 || m==2){
        if(m==0){
            m = 1;
        }
        else if(m > 12){
            this->month = 12;
        }
        else if(m <1){
            this->month = 1;
        }
        else {
            this->month = m;
        }
        if(m==2){
            if(isLeap(y)){
                if( d>= 29){
                    this->day = 29;
                }
            }
            else{
                if(d> 28){
                    this->day = 28;
                }
            }
        }
        if(d<=0){
            this->day = 1;
        }
        else if(d > daysPerMonth(m, y)){
            this->day =  daysPerMonth(m, y);
        }
        else if(d<0){
            this->day = 1;
        }
        else if(d > 31){
            this->day = 31;
        }
        else {
            this->day = d;
        }
        
        if(d != this->day){
            cout<< "Invalid date values: Date corrected to ";
            this->year = y;
            this->monthName = mn;
            printNumeric();
            cout<<"."<< endl;
        }
        else if(m != this->month){
            cout<< "Invalid month name: the Date was set to ";
            this->year = y;
            this->monthName = mn;
            printNumeric();
            cout<<"."<< endl;
        }
        
    }
    else {
        this->month = m;
        this->day = d;
        
    }
       this->year = y;
       this->monthName = mn;
   }


   /* Outputs to the console (cout) a Date exactly in the format "3/1/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const{
       cout<<month<< "/"<< day<< "/" << year;
   }


   /* Outputs to the console (cout) a Date exactly in the format "March 1, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const{
       cout<<name(month)<< " "<< day<< ", " << year;
   }

 public:// 

// (year % 4 == 0) implies leap year
// except (year % 100 == 0) implies NOT leap year
// except (year % 400 == 0) implies leap year
   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const{
        bool leap_year;
        if (y % 4 == 0)
        {
            leap_year = true;
        }
        if (y % 100 == 0)
        {
            leap_year = false;
        }
        if (y % 400 == 0)
        {
            leap_year = true;
        }
        return leap_year;
    }


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-­leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const{
       if(m == 2){
           if(isLeap(y)){
               return 29;
           }else{
               return 28;
           }
       }
       if(m>=1 && m<8){
           if(m%2==1){
               return 31;
           }
           else {
               return 30;
           }

       }
       if(m>=8 && m<=12){
           if(m%2==0){
               return 31;
           }
           else {
               return 30;
           }
       }
       return 31;
   }

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const{
       switch (m)
       {
       case 1:
           return "January";
           break;
        case 2:
           return "February";
           break;
        case 3:
           return "March";
           break;
        case 4:
           return "April";
           break;
        case 5:
           return "May";
           break;
        case 6:
           return "June";
           break;
        case 7:
           return "July";
           break;
        case 8:
           return "August";
           break;
        case 9:
           return "September";
           break;
        case 10:
           return "October";
           break;
        case 11:
           return "November";
           break;
        case 12:
           return "December";
           break;
        default:
           break;
       }
       return "January";
   }

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const{
       if(mn == "January" || mn == "january" ){
           return 1;
       }
       if (mn == "February" || mn == "february"){
           return 2;
       }
       if (mn =="March" || mn =="march"){
           return 3;
       }
       if (mn == "April" || mn == "april"){
           return 4;
       }
       if (mn == "May" || mn == "may"){
           return 5;
       }
       if (mn == "June" || mn == "june"){
           return 6;
       }
       if (mn == "July" || mn == "july"){
           return 7;
       }
       if (mn == "August" || mn == "august"){
           return 8;
       }
       if (mn == "September" || mn == "september"){
           return 9;
       }
       if (mn == "October" || mn == "october"){
           return 10;
       }
       if (mn == "November" || mn == "november"){
           return 11;
       }
       if (mn == "December" || mn == "december"){
           return 12;
       }
       return 0;
   }
};



Date getDate();

int main() {

   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;

   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}