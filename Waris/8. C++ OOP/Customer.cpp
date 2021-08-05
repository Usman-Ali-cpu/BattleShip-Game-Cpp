#include <iostream>
#include "Customer.h"
using namespace std;


    Customer::Customer(){
        cardNumber = "000000000000";
        NIF = 00000;
        phoneNumber = "+000000000";
        name = "Unknown";
        address = "Unknown";
    }
    Customer::Customer(string card, long int NIF, string phNum, string n, string add){
        cardNumber = card;
        NIF = NIF;
        phoneNumber = phNum;
        name = n;
        address = add;
    }
    void Customer::setCardNumber(string card){
        this->cardNumber = card;
    }
    void Customer::setNIF(long int nif){
        this->NIF = nif;
    }
    void Customer::setPhoneNum(string num){
        this->phoneNumber = num;
    }
    void Customer::setName(string n){
        this->name = n;
    }
    void Customer::setAddress(string add){
        this->address = add;
    }

    string Customer::getCardNumber(){
        return this->cardNumber;
    }
    long int Customer::getNIF(){
        return this->NIF;
    }
    string Customer::getPhoneNum(){
        return this->phoneNumber;
    }
    string Customer::getName(){
        return this->name;
    }
    string Customer::getAddress(){
        return this->address;
    }
    void Customer::displayCustomer(){
        cout<< "Customer Name : "<< this->name<< ",  Customer NIF: "<< this->NIF
        << "Customer Card No: " <<this->cardNumber << ",  Customer Phone Number: "
        << this->phoneNumber << ",  Customer Address : " << this->address<< endl;
    }
