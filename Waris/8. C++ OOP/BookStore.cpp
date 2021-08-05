#include <iostream>
#include <vector>
#include "BookStore.h"
using namespace std;

    BookStore::BookStore(string a_name){
        this->storeName = a_name;
    }
    vector<Customer> BookStore::getCustomers(){
        return customers;
    }
    bool BookStore::isCustomerPresent(long int Nif){
        int size = customers.size();
        for(int i=0; i<size; i++){
            if(customers.at(i).getNIF() == Nif){
                return true;
            }
        }
        return false;
    }
    void BookStore::addPurchase(Purchase pur){
        purchases.push_back(pur);
    }
    void BookStore::addCustomer(Customer cus){
        customers.push_back(cus);
        cout<< "Customer Has Been Added Successfully "<< endl;
    }
    void BookStore::addInvoices(Invoices in){
        invoices.push_back(in);
    }
    void BookStore::displayPurchase(){
        cout<< "Purchases in "<< this->storeName<< endl;
        int size = purchases.size();
        for(int i=0; i< size; i++){
            cout<< "Purchase #"<< i+1<< endl;
            purchases.at(i).displayPurchase();
        }
    }
    void BookStore::displayCustomer(){
        cout<< "Customers in "<< this->storeName<< endl;
        int size = customers.size();
        for(int i=0; i< size; i++){
            cout<< "Customer #"<< i+1<< endl;
            customers.at(i).displayCustomer();
        }
    }
    void BookStore::displayInvoices(){
        cout<< "Invoices in "<< this->storeName<< endl;
        int size = invoices.size();
        for(int i=0; i< size; i++){
            cout<< "Invoice #"<< i+1<< endl;
            invoices.at(i).display();
        }
    }