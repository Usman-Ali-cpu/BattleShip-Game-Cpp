
#pragma once
#ifndef DESCRIPTION_H
#define DESCRIPTION_H
#include <iostream>
using namespace std;

class Description{
    string title;  // private data member title of book
    string author; // private data member author of book
    string publisher; // private data member publisher of book
    long int ISBN; // private data member ISBN of book
public:
    Description(); // default constructor
    Description(string a_title, string a_author, string a_publisher, long int a_ISBN ); // parameterize constructor 
    void setTitle(string t);   // setter for private member title
    void setAuthor(string a);   // setter for private member  author
    void setpublisher(string p);  // setter for private member publisher 
    void setISBN(long int i);  // setter for private membe ISBN

    string getTitle();  // getter for private member title
    string getAuthor(); // getter for private member  author
    string getpublisher(); // getter for private member publisher 
    long int getISBN(); // getter for private membe ISBN
    void displayBook(); // display detail of book


};

#endif