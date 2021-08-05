#pragma once
#ifndef PURCHASE_H // if not define purchase class, 
#define PURCHASE_H // define purchase class
#include <iostream>
#include "Description.h" // including Description class 
using namespace std;

class Purchase {
    string date; // private data member date
    Description bookDescription; // private data member object of description class 
    double amountPaid; // // private data member amount paid
public:
    Purchase(); // default constructor 
    // parameterize constructor 
    Purchase(string a_title, string a_author, string a_publisher, long int a_ISBN , string a_date, double amount);
    
    void setPurchaseDate(string d);// setter for date 
    void setAmoutPaid(double a); // setter for amount paid
    void setDescription(Description d); // setter for description of book
    string getPurchaseDate(string d);// getter for date 
    double getAmoutPaid(double a);// getter for amount paid
    Description getDescription(Description d); // getter for description of book
    void displayPurchase(); // display the data of purchase 
};

#endif