#pragma once 
#ifndef ACCOUNT_H  // check if class is already not define 
#define ACCOUNT_H   // define class 
#include <iostream>
using namespace std;

class Account{
protected:          // projected members for accessing in drived class 
    int *deposit;   // pointer to int to hold deposit 
    int size;
    double *accumlator; // pointer to double to hold accumlated
public:
    Account(){
        size = 5;
        deposit = new int[size];
        accumlator = new double[size];
        for (int i = 0; i < size; i++){
            accumlator[i] = deposit[i] = 0;
        }
    }
    void input(){
        int j = size;
        for (int i = 0; i < size; i++){ // loop through size of deposit
        do{
            cout << "Enter the "<< i+1 <<"th deposit: (this will be invested for" <<j << "years):  ";   
            cin>> deposit[i];  // input a number for deposit for years
        } while (deposit[i] < 0);
            j--;
        }
    }
    int & operator[](int i){
        return deposit[i]; // operator[] to allow accessing and mutating a single deposit 
    }
    ~Account(){ // destructor for account 
        delete[] deposit;   // deleting array to which deposit pointer pointing 
        deposit = NULL;    // Null the pointer 
        delete[] accumlator; // deleting array to which accumulator pointer pointing 
        accumlator = NULL;  // Null the pointer 
    }
};
#endif 