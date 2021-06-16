#include <string>
#include <iostream>
using namespace std;

#pragma once
#ifndef BOOK_H
#define Book_H




class BookData{
public:
    string title; // to store title of book
    int ID;       // to store ID of book
    int aisle;    // to store aisle of book
    string bookType; // to store type of book

    BookData(){
        this->title = "";
        this->ID = 0;
        this->aisle = 0;
        this->bookType = "";
    } // it is default constructor. 

    BookData(string a_title, int a_id, int a_aisle, string a_bookType){
        this->title = a_title;
        this->ID = a_id;
        this->aisle = a_aisle;
        this->bookType = a_bookType;
    } // it is parameterize contructor

    void add(string a_title, int a_id, int a_aisle, string a_bookType){
        this->title = a_title;
        this->ID = a_id;
        this->aisle = a_aisle;
        this->bookType = a_bookType;
    } // it would insert data to data members of BookData.
    BookData &operator=(BookData &b){
        this->title = b.title;
        this->ID = b.ID;
        this->aisle = b.aisle;
        this->bookType = b.bookType;
        return *this;
    } // This is assingment operator to assign one bookData to other.
    void display(){
        cout << "Title : " << this->title << endl;
        cout << "ID : " << this->ID << endl;
        cout << "Aisle : " << this->aisle << endl;
        cout << "Type : " << this->bookType << endl << endl;
    } // it will display all data members of class

    ~BookData(){

    } // it is destructor to destroy object
};

// Book class is made to make a array of bookdata objects. 
// it would have size of array and pointer to array. 
class Book{
    int size;      // to get size of array of object
    BookData* b;   // to pointer array of bookData objects
    int count;     // it would of index of array.

public:
    Book(); // defualt contructor
    Book(int s); // it is parameterize constructor to make array of object of given size
    int addBook(string a_title, int a_id, int a_aisle, string a_bookType); // to add BookData in array
    bool checkExist(int id, string title); // to check whether book is already exists or not.
    void display();  // display All the books in array
    void sort(); // it would sort all the books in array in descending order.
    void boundSort(int l, int h); // it would get book in given range of ids and then sort in descending order and display it.
    void bookTypeWithString(string sub); // it would find passing substring from all Booktypes, 
                                        // and from these objects find object of having large title and then display it.
    ~Book(); // destructor. it would all the objects of array 
};

#endif