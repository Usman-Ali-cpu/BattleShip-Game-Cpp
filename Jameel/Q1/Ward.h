#pragma once 
#ifndef Ward_H
#define Ward_H
#include "SubWard.h"
#include<iostream>
using namespace std;

class Ward{
    SubWard *sub;
    string name;
    int count;

public :
    Ward(){
        name = "Unknown";
        count = 0;
         sub = new SubWard[5];
    }
    Ward(string n){
        name = n;
        sub = new SubWard[5];
          count = 0;
    }
    string getName(){
        return this->name;
    }
    void setName(string n){
        this->name = n;
    }
    bool addWard(){
        string n;
        long int num; 
        cout << "Enter name : ";
        cin >> n;
        if(count < 5){    
            SubWard s(n);
            sub[count] = s;
            cout << "Ward has been Added " << endl;
            return true;
        }
        return false;
    }

    
    int getNumOfPateintinAllWard(){
        int total = 0;
        for (int i = 0; i < count; i++){
            int sum = sub[i].getNumOfPateint();
            total += sum;
        }
        return total;
    }

    int getNumOfPateintinSpecificWard(int i){
        int total = 0;
        if(i<5){
            int sum = sub[i].getNumOfPateint();
            total += sum;
        }
        return total;
    }


bool remove(){
    
    cout << "Enter Ward name to remove : ";
    string  name;
    for (int i = 0; i < count; i++){
        if(sub[i].getName() == name){
            cout << "Found ward to remove " << endl;
            sub[i].bremove = true;
        }  
    }
    cout << "Pateint Not Found ! " << endl;
    return false;
}


SubWard getWardOFPateint(Pateint p){
    for (int i = 0; i < count; i++){
        if(sub[i].isRegistered(p.getRegistration())){
            return sub[i];
        }
    }
}

void printWard(){
    for (int i = 0; i < count; i++){
        if(sub[i].bremove == false)
        {
            cout<< "Ward name : "  << sub[i].getName() << endl;
        }
    }  
}
    SubWard &operator[](int i){
        if(i<count){
            return sub[i];
        }
    }

};

#endif


