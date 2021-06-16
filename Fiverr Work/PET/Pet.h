#pragma once
#ifndef BOOK_H
#define Book_H
#include <string>
using namespace std;


class Pet{
public:
    Pet(string nm, int initialHealth);
    void eat(int amt);
    void play();
    string getname() const;
    int health() const;
    bool alive() const;
private:
    string name;
    int healthlevel;
};


#endif