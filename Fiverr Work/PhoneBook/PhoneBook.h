#pragma once
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include "Entry.h"
using namespace std;

class PhoneBook{
private:
    int max;
    int current;
    Entry *entries;
    int find(Entry e);
public:
    PhoneBook();
    ~PhoneBook();
    void add(Entry e);
    Entry getEntry(int i);
    void remove();
    void removeWithPhone(int phone);

    // Display is constant because it is not updating any value. 
    // Moreever it is using a constant inside it.
    void Display() const;
};




#endif


