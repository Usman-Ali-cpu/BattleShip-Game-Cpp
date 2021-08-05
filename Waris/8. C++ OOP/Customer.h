#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
using namespace std;


class Customer{
    string cardNumber; // private data member Cardnumber 
    long int NIF; // private data member NIF of customer
    string phoneNumber; // private data member phoneNumber of customer
    string name; // private data member name of customer
    string address; // private data member  address of customer 
public: 
    Customer(); // deafualt constructor 
    Customer(string card, long int NIF, string phNum, string n, string add); // parameterize constructor 
    void setCardNumber(string card); // setter for private member card number  
    void setNIF(long int nif); // setter for private member NIF 
    void setPhoneNum(string num); // setter for private member phone number
    void setName(string n); // setter for private member name
    void setAddress(string add); // setter for private member address

    string getCardNumber(); // getter for private member card number
    long int getNIF(); // getter for private member NIF
    string getPhoneNum(); // getter for private member phone number
    string getName(); // getter for private member name
    string getAddress(); // getter for private member address
    void displayCustomer(); // display detail of customer 

};


#endif