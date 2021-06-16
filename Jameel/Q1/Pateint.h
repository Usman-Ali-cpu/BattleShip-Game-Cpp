#pragma once 
#ifndef PATEINT_H
#define PATEINT_H

#include <iostream>
#include "Date.h"
#include <iterator>
#include <list>
using namespace std;


struct Entry
{
    Date addmissionDate;
    Date dischargeDate;
    string admitAward;
};


class Pateint{
    string name;
    Date dob;
    long int regNum;
    list<Entry> li;
public:
    Pateint(){
        name = "Unknown";
        Date d;
        this->dob = d;
        this->regNum = 0;
    }
    Pateint(string name, Date date, int num){
        this->name = name;
        this->dob = date;
        this->regNum = num;
    }
    string getName (){
        return this->name;
    }
    Date getDob (){
        return this->dob;
    }
    long int getRegistration(){
        return this->regNum;
    }
    void setName (string n){
        this->name = n;
    }
    void setDob (Date d){
        this->dob = d;
    }
    void setRegistration(long int n){
        this->regNum = n;
    }
    void addEntry(Entry e){
        li.push_back(e);
    }
    void printEntryList(){
        for( Entry l: this->li)
        {
            cout << "Addmission Date : ";
            l.addmissionDate.printDate();
            cout << "\nDischarge Date : ";
            l.dischargeDate.printDate();
            cout << "Admit Award : " << l.admitAward << endl
                 << endl;
        }
    }
    friend bool operator==(Pateint &p, Pateint &p1);
    friend ostream &operator<<(ostream &out, Pateint &p);
};


ostream& operator<<(ostream& out, Pateint& p)
{
    out << "Patient Name : " << p.getName() << endl;
    out << "Date of birth: ";
    p.getDob().printDate();
    out  << "Registration Number : "<< p.getRegistration() << endl;
    p.printEntryList();
    return out;
}

bool operator==(Pateint & p, Pateint & p1){
        if(p.regNum == p1.regNum){
            return true;
        }
        return false;
}

#endif