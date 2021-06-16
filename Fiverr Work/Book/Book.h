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

/*
Book::Book(){
        size = 1;
        count = 0;
        b = new BookData[size];
}
Book::Book(int s){
        size = s;
        count = 0;
        b = new BookData[size];
}
int Book::addBook(string a_title, int a_id, int a_aisle, string a_bookType){
        if(count<size){ 
            if(!checkExist(a_id, a_title)){
                b[count].title = a_title;
                b[count].ID = a_id;
                b[count].aisle = a_aisle;
                b[count].bookType = a_bookType;
                count++;
                return 1;
            }
        }
    return 0;
}
bool Book::checkExist(int id, string title){
        for (int i = 0; i < count; i++){
            if(b[i].title == title || b[i].ID == id){
                return true;
            }
        }
    return false;
}
void Book::display(){
    if(count==0){
        cout << "You have added no Book" << endl;
    }
    else 
        for (int i = 0; i < count; i++){
            cout << "Title : " << this->b[i].title << endl;
            cout << "ID : " << this->b[i].ID << endl;
            cout << "Aisle : " << this->b[i].aisle << endl;
            cout << "Type : " << this->b[i].bookType << endl << endl;
        }
}
void Book::sort(){
        for (int i = 0; i < count; i++){
            BookData data = b[i];
            for (int j = i; j < count; j++){
                if(data.ID < b[j].ID){
                    BookData temp;
                    temp = b[i];
                    b[i] = b[j];
                    b[j] = temp;
                    break;
                }
            }
        }
}
void Book::boundSort(int l, int h){
        Book temp(size);
        for(int i=0; i<count; i++){
            if(b[i].ID >= l && b[i].ID <= h){
                temp.addBook(b[i].title, b[i].ID, b[i].aisle, b[i].bookType);
            }
        }
        temp.sort();
        temp.display();
}
void Book::bookTypeWithString(string sub){
        BookData temp;
        bool check= false;
        for (int j = 0; j < count; j++){

            string type = b[j].bookType;
            int length = sub.length();
            for (int i = 0; i < type.length(); i++){
                if (type.substr(i, length) == sub){
                    if(b[j].title.length() >= temp.title.length() || temp.title==""){
                        temp.add(b[j].title, b[j].ID, b[j].aisle, b[j].bookType);
                        check = true;
                        break;
                    }
                }
            }

        }
        if(check){      
            temp.display();
        }else {
            cout << "Not found " << endl;
        }
    }
Book::~Book(){
        delete[] b;
        b = NULL;
}
*/
#endif