#pragma once 
#ifndef ACCOUNTTYPE_H  // check if class is already not define 
#define ACCOUNTTYPE_H  // define class 
#include <iostream>
#include "Account.h" // inlcude a base class 
using namespace std;


const int PRINCIPAL = 1000; // declaring const 


class AccountType: public Account{  // public inheritance take place 
    double interestRate;
    double *savingInterest;    // pointer to double to point array of interests

public:
    AccountType(){
        size = 5;                       // declaring size for array
        savingInterest = new double[size];      // creating array of size 5 
        interestRate = 0.19;                // interest rate for saving account 
        for (int i = 0; i < size; i++){
            savingInterest[i] = 0;   // initializing the array 
        }
    }
    AccountType &copy(AccountType & copy){          // copy constructor 
        size = copy.size;                          // copying the size 
        for (int i = 0; i < size; i++){
            this->accumlator[i] = copy.accumlator[i];    // copying entries of accumulator array
            this->deposit[i] = copy.deposit[i];          // copying entries of deposit array
            this->savingInterest[i] = copy.savingInterest[i]; // copying interest rate
        }
        return *this;
    }
    AccountType &operator=(AccountType & assign){   // assignment operator 
        size = assign.size;                         // assigning size of array
        for (int i = 0; i < size; i++){
            this->accumlator[i] = assign.accumlator[i]; // aasigning entries of accumulator array 
            this->deposit[i] = assign.deposit[i]; // // aasigning entries of deposit array
             this->savingInterest[i] = assign.savingInterest[i]; // copying interest rate
        }
        return *this;
    }
    void setInterestRate(double rate){ // setter to set interest rate when account type we want to change
        this->interestRate = rate; //setting rate 
    }
    void calculateInterest(){  // calculate interest rate
        int j = size;
        for (int i = 0; i < size; i++){
            savingInterest[i] = ( PRINCIPAL  * (1 + interestRate) * (i+1) ) - PRINCIPAL ; // it would calclate compound interest for number of years
        }
    }
    void displayAmount(){
        calculateInterest(); // it would calculate compound interest 
        int a = 0; 
        int j = size-1;
        for (int i = 0; i < size; i++){
            a += deposit[i];  // add deposit of each year 
            accumlator[i] = a; // add deposit of previous years to new  
            cout << "Accumulated deposit+interest after the year "<< i+1 <<": $ " << accumlator[i] + savingInterest[i]<< endl; // it would display accumulated (deposit and interest)
            j--;
        }
    }
    ~AccountType(){
        delete[] savingInterest; // delete array 
        savingInterest = NULL;  // delete pointer by null
    }
};


#endif