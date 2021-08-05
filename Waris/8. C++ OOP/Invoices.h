
#pragma once
#ifndef INVOICES_H
#define INVOICES_H
#include <iostream>
using namespace std;

class Invoices{
    string date; // private data member date
    long int NIF; // private data member NIF
    double totalPaid; // private data member total paid
public:
    Invoices(); // default constructor 
    Invoices(string d,long int Nif, double paid); // parameterize constructor
    void setDate(string d);  // setter for private member date
    void setNIF(long int NIF); // setter for private member NIF
    void setTotalpaid(double paid); // setter for private member total paid
    void display();  // display detail of Invoices
};

#endif