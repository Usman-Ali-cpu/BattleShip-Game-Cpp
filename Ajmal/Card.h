#pragma once
#ifndef CARD_H // if class is already not define
#define CARD_H // define this class
#include <iostream>

class Card
{
private:
    std::string suits; // string to store suit of card
    std::string value; // string to store value of card

public:
    Card();                                   // defualt constructor
    Card(std::string suits, std::string val); // parameterize constructor

    void print();                // method to print data of suits and vlaue of card
    bool isEqualSuits(Card c);   // bool type method to check wether two card's suits are equal or not
    bool isEqualValue(Card c);   // bool type method to check wether two card's value are equal or not
    bool isGreaterValue(Card c); // bool type method to check wether one card's value are greater than or not
    bool isLessValue(Card c);    // bool type method to check wether one card's value are less than or not
};

#endif