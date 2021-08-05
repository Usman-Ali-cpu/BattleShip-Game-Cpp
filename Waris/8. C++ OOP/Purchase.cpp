#include <iostream>
#include "Purchase.h"
#include "Description.h"
using namespace std;

    Purchase::Purchase(){
        date = "unknown"; 
        amountPaid = 0;
    }
    Purchase::Purchase(string a_title, string a_author, string a_publisher, long int a_ISBN , string a_date, double amount){
        this->date = a_date;
        this->amountPaid = amount;
        this->bookDescription.setTitle(a_title);
        this->bookDescription.setAuthor(a_author);
        this->bookDescription.setpublisher(a_publisher);
        this->bookDescription.setISBN(a_ISBN);
    }
    void Purchase::setPurchaseDate(string d){
        this->date = d; // assigning value to date
    }
    void Purchase::setAmoutPaid(double a){
        this->amountPaid = a; // assigning value to amount paid
    }
    void Purchase::setDescription(Description d){
        this->bookDescription = d; // assigning value to description
    }
    string Purchase::getPurchaseDate(string d){
        return this->date; // returning value of date
    }
    double Purchase::getAmoutPaid(double a){
        return this->amountPaid; // returning value of ammount paid
    }
    Description Purchase::getDescription(Description d){
        return this->bookDescription; // returning value of description
    }
    void Purchase::displayPurchase(){ 
        cout<< "Date = " << this->date<< endl; // display date
        cout<< "Amount Paid : " << this->amountPaid<< endl; // display amount 
        bookDescription.displayBook(); // display description by calling member function of description class 
    }