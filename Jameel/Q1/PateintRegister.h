#pragma once 
#ifndef PATEINTREGISTER_H
#define PATEINTREGISTER_H


#include <iostream>
#include "Date.cpp"
#include "Pateint.h"
#include <list>
// #include <iterator>
using namespace std;



class PateintRegister{
private:
    list<Pateint> pList;
public:

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
            pList.push_back(p);
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
        for (Pateint p: pList){
            count++;
        }
        return count;
    }


bool remove(){
    list<Pateint>::iterator it = pList.begin();
    cout << "Enter Registration Number to remove : ";
    int regnum;
    int j = 0;
    
        for (const Pateint &p: pList){
            Pateint e = p;
            if(e.getRegistration() == regnum){
                // pList.remove(p);
            }
            return true;
        }
    cout << "Pateint Not Found ! " << endl;
    return false;
}

void individualPateint(){
    for (Pateint p: pList){
        cout << "\n***********************\n";
        cout << p;
        cout << "\n***********************\n";
    }
}

bool isRegistered(int regnum){
    for (Pateint p: pList){
        if(p.getRegistration() ==regnum){
            return true;
        }
    }
    return false;
}

Pateint &operator[](int i){
    if(i<pList.size()){
        int j = 0;
        for (Pateint &p: pList){
            if(i==j){
                return p;
            }
            j++;
        }
    }
}

void printRegistrations(){
    int i = 0;
    for (Pateint p: pList){
        cout << i+1  <<". Registration Number : " << p.getRegistration() << endl;
    }
}



};


#endif








