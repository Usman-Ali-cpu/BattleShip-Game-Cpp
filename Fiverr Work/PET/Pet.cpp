#include <iostream>
#include "Pet.h"
using namespace std;

void reportStatus(const Pet *p){
    cout << p->getname() << " has health level " << p->health();
    if(!p->alive()){
        cout << ", so has died";
    }
    cout << endl;
}

void careFor(Pet * p, int d){
    if(!p->alive()){
        cout << p->getname() << " is still died " << endl;
        return;
    }
    if(d%3 == 0){
        cout << "You forget to feed " << p->getname() << endl;
    }
    else{
        p->eat(1);
        cout << "You fed " << p->getname() << endl;
    }
    p->play();
    reportStatus(p);
}



bool Pet::alive() const{
        return healthlevel <= 0 ? false : true;
}
int Pet::health() const{
        return healthlevel;
}
string Pet::getname() const{
        return name;
}
void Pet::play(){
        healthlevel--;
}
void Pet::eat(int amt){
        healthlevel += amt;
}
Pet::Pet(string nm, int initialHealth){
        name = nm;
        healthlevel = initialHealth;
}
