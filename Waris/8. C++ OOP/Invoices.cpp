#include <iostream>
#include "Invoices.h"
using namespace std;



    Invoices::Invoices(){
        this->date = "01/01/2021";
        this->NIF = 00000000;
        this->totalPaid = 0;
    }
    Invoices::Invoices(string d,long int Nif, double paid){
        this->date = d;
        this->NIF = Nif;
        this->totalPaid = paid;
    }
    void Invoices::setDate(string d){
        this->date = d;
    }
    void Invoices::setNIF(long int NIF){
        this->NIF = NIF;
    }
    void Invoices::setTotalpaid(double paid){
        this->totalPaid = paid;
    }
    void Invoices::display(){
        cout<< "Date : " << this->date<< ", Customer NIF : "<< this->NIF<< ", Total Paid : "<< this->totalPaid<< endl;
    }