#pragma once
#include <iostream>
using namespace std;

class String
{
private:
    char *string;
    int size;

public:
    String(const char *s = ""); // constructor
    String(const String &);
    ~String();    // destructor
    void print(); // print the string
    void change(const char *);
};
