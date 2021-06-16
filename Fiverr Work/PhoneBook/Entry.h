#pragma once
#ifndef ENTRY_H
#define ENTRY_H

#include <iostream>
using namespace std;

class Entry{
private:
    static int count;
    string name;
    long int phoneNumber;
    string address;
public:
    Entry();
    void setValue(string n, int phone, string add);
    void display() const;
    bool operator==(Entry e);
    int getPhoneNumber();
    static int getNumEntries();
    friend void print(Entry &, Entry &);
    ~Entry();
};


#endif