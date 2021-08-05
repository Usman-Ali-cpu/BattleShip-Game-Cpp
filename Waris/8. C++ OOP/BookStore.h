
#pragma once
#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include <iostream>
#include <vector>
#include "Customer.cpp" // including define members of customer 
#include "Invoices.cpp"  // including define members of Invoices
#include "Description.cpp"  // including define members of book description
#include "Purchase.cpp"  // including define members of purchase
using namespace std;

class BookStore{
    string storeName; // private data member of name
    vector<Customer> customers; // private data member of list of customers
    vector<Invoices> invoices; // private data member of list of invoices
    vector<Purchase> purchases; // private data member of list of purchases
public:
    BookStore(string a_name); // parameterize constructor, take name of store as a parameter 
    vector<Customer> getCustomers(); // return the list of customers
    bool isCustomerPresent(long int Nif); // check if customer is present or not 
    void addPurchase(Purchase pur); // add purchase to the list of purchase
    void addCustomer(Customer cus);  // add customer to the list of customers
    void addInvoices(Invoices in);  // add invoice to the list of invoices
    void displayPurchase(); // display list of purchases
    void displayCustomer(); // display list of Customers
    void displayInvoices(); // display list of Invoices
};
#endif
