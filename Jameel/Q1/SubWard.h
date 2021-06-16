#pragma once 
#ifndef SubWard_H
#define SubWard_H
#include "Pateint.h"
#include<iostream>
using namespace std;

class SubWard{
    list<Pateint> wList;
    string name;

public :

    SubWard(){
        name = "Unknown";
    }
    SubWard(string n){
        name = n;
    }
    string getName(){
        return this->name;
    }
    void setName(string n){
        this->name = n;
    }
    bool bremove = false;
    bool addPateint(){
        string n;
        long int num; 
        cout << "Enter name : ";
        cin >> n;
        cout << "Enter Registration Num : ";
        cin >> num;
        int d, m, y;
        cout << "Enter Date of birth (01/01/2021): \n";
        cout << "Enter Day : ";
        cin >> d;
        cout << "Enter Month : ";
        cin >> m;
        cout << "Enter year : ";
        cin >> y;
        Date date(y, m, d);
        Pateint p(n, date, num);
        if(!isRegistered( num)){
            wList.push_back(p);
            cout << "Registered Successfully " << endl;
            return true;
        }
        else {
            cout << "Pateint Already Registered " << endl;
            return false;
        }
    }

    
    int getNumOfPateint(){
        int count = 0;
        for (Pateint p: wList){
            count++;
        }
        return count;
    }


bool remove(){
    cout << "Enter Registration Number to remove : ";
    int regnum;
    for (const Pateint &p: wList){
        Pateint c = p;
        if(c.getRegistration() == regnum){
            // wList.remove(p);
            return true;
        }
    }
    cout << "Pateint Not Found ! " << endl;
    return false;
}

void individualPateint(){
    for (Pateint p: wList){
        cout << p;
    }
}

bool isRegistered(int regnum){
    for (Pateint p: wList){
        if(p.getRegistration() ==1){
            return true;
        }
    }
    return false;
}

Pateint &operator[](int i){
    if(i<wList.size()){
        int j = 0;
        for (Pateint &p: wList){
            if(i==j){
                return p;
            }
            j++;
        }
    }
}

void printRegistrations(){
    int i = 0;
    for (Pateint p: wList){
        cout << i+1  <<". Registration Number : " << p.getRegistration() << endl;
    }
}




};

#endif