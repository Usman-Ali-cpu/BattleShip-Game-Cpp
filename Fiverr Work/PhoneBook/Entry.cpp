#include <iostream>
#include "Entry.h"
using namespace std;


Entry::Entry(){
    count++;
    this->name = "unkown";
    this->phoneNumber = 0;
    this->address = "unknown";
}
Entry::~Entry(){
        count--;
}
void Entry::setValue(string n, int phone, string add){
        this->address = add;
        this->phoneNumber = phone;
        this->name = n;
}
void Entry::display() const{
    cout << "Entry Name : " << this->name << endl;
    cout << "Entry Phone : " << this->phoneNumber << endl;
    cout << "Entry Address: " << this->address << endl<< endl;

}
bool Entry::operator==(Entry e){
        if(this->name != e.name){
            return false;
        }
        if(this->address != e.address){
            return false;
        }
        if(this->phoneNumber != e.phoneNumber){
            return false;
        }
        return true;
}
int Entry::getPhoneNumber(){
    return this->phoneNumber;
}
int Entry::getNumEntries(){
    return count;
}
void print(Entry &a, Entry&b){
    a.display();
    b.display();
}
int Entry::count = 0;

