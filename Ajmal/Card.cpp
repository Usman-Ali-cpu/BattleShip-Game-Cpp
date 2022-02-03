#include <iostream>
#include "Card.h"
#include <string>
using namespace std;

// defualt constructor
Card::Card()
{
    value = ""; // set value to blank
    suits = ""; // set suits to blank
}
// parameterize constructor
Card::Card(std::string suits, std::string val)
{
    this->suits = suits; // set suits
    this->value = val;   // set value
}
void Card::print()
{
    cout << "Value : " << this->value << ",  Suits : " << this->suits; // print value and suits of card
}
bool Card::isEqualSuits(Card c)
{
    if (c.suits == this->suits) // check if suit of this card and passing card is equal
    {
        return true; // return true if equal
    }
    return false; // return false if not equal
}
bool Card::isEqualValue(Card c)
{
    if (c.value == this->value) // check if value of this card and passing card is equal
    {
        return true; // return true if equal
    }
    return false; // return false if not equal
}
bool Card::isGreaterValue(Card c)
{
    int val1, val2;       // int type variables to store values
    char a = c.value[0];  // get first char of string to check if it is number or not
    if (a > 48 && a < 57) // check if it is integer type
    {
        val1 = stoi(c.value); // get value
    }
    else
    {
        if (c.value == "Jack") // if it is jack
        {
            val1 = 11; // assign value 11
        }
        if (c.value == "Queen") // if it is Queen
        {
            val1 = 12; // assign value 12
        }
        if (c.value == "King") // if it is King
        {
            val1 = 13; // assign value 13
        }
        if (c.value == "Ace") // if it is Ace
        {
            val1 = 14; // assign value 14
        }
    }
    a = this->value[0];   // get first char of string to check if it is number or not
    if (a > 48 && a < 57) // check if it is digit
    {
        val2 = stoi(this->value); // convert string type to int
    }
    else
    {
        if (c.value == "Jack") // if it is jack
        {
            val1 = 11; // assign value 11
        }
        if (c.value == "Queen") // if it is Queen
        {
            val1 = 12; // assign value 12
        }
        if (c.value == "King") // if it is King
        {
            val1 = 13; // assign value 13
        }
        if (c.value == "Ace") // if it is Ace
        {
            val1 = 14; // assign value 14
        }
    }
    if (val2 > val1)
    {
        return true; // return true if value is greater
    }
    return false;
}
bool Card::isLessValue(Card c)
{
    int val1, val2;
    char a = c.value[0];  // get first char of string to check if it is number or not
    if (a > 48 && a < 57) // check if it is digit or not
    {
        val1 = stoi(c.value);
    }
    else
    {
        if (c.value == "Jack") // if it is jack
        {
            val1 = 11; // assign value 11
        }
        if (c.value == "Queen") // if it is Queen
        {
            val1 = 12; // assign value 12
        }
        if (c.value == "King") // if it is King
        {
            val1 = 13; // assign value 13
        }
        if (c.value == "Ace") // if it is Ace
        {
            val1 = 14; // assign value 14
        }
    }
    a = this->value[0];   // get first char of string to check if it is number or not
    if (a > 48 && a < 57) // check if it is digit or not
    {
        val2 = stoi(this->value); // convert string type to int
    }
    else
    {
        if (c.value == "Jack") // if it is jack
        {
            val1 = 11; // assign value 11
        }
        if (c.value == "Queen") // if it is Queen
        {
            val1 = 12; // assign value 12
        }
        if (c.value == "King") // if it is King
        {
            val1 = 13; // assign value 13
        }
        if (c.value == "Ace") // if it is Ace
        {
            val1 = 14; // assign value 14
        }
    }
    if (val2 < val1)
    {
        return true; // if value is less than then return true
    }
    return false; // else return false
}