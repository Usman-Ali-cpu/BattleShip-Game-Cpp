#include <iostream>
#include "PhoneBook.h"
using namespace std;




PhoneBook::PhoneBook(){
        max = 20;
        entries = new Entry[max];
        current = 0;
    }
    int PhoneBook::find(Entry e){
        for (int i = 0; i < current; i++){
            if(entries[i] == e){
                return i;
            }
        }
        return -1;
    }
    PhoneBook::~PhoneBook(){
        delete[] entries;
        entries = NULL;
    }
    void PhoneBook::add(Entry e){
        if(current < max){
            entries[current++] = e;
        }
        else {
            cout << "Phone Book is Full" << endl;
        }
    }
    Entry PhoneBook::getEntry(int i){
        return entries[i];
    }
    void PhoneBook::remove(){
        if(current > 0){
            current--;
        }
        else {
            cout << "Phone Book is Empty" << endl;
        }
    }
    void PhoneBook::removeWithPhone(int phone){
        Entry e;
        bool flag = false;
        e.setValue("unknown", 0, "unknown");
        for (int i = 0; i < current; i++){
            if(entries[i].getPhoneNumber() == phone){
                cout << "This Entry is going to delete !" << endl;
                entries[i].display();
                entries[i] = e;
                flag = true;
                break;
            }
        }
        if(!flag){
            cout << "We have not registered this Phone Number!" << endl;
        }
    }

    // Display is constant because it is not updating any value. 
    // Moreever it is using a constant inside it.
    void PhoneBook::Display()const{
        for (int i = 0; i < this->current; i++){
            entries[i].display();
        }
    }