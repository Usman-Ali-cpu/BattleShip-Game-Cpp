#include <iostream>
#include "Description.h"
using namespace std;


    Description::Description(){
        title = "Untitled";
        author = "Unknown";
        publisher = "Unknown";
        ISBN = 000000000000;
    }
    Description::Description(string a_title, string a_author, string a_publisher, long int a_ISBN ){
        title = a_title;
        author = a_author;
        publisher = a_publisher;
        ISBN = a_ISBN;
    }
    void Description::setTitle(string t){
        this->title = t;
    }
    void Description::setAuthor(string a){
        this->author = a;
    }
    void Description::setpublisher(string p){
        this->publisher = p;
    }
    void Description::setISBN(long int i){
        this->ISBN = i;
    }

    string Description::getTitle(){
        return this->title ;
    }
    string Description::getAuthor(){
        return this->author;
    }
    string Description::getpublisher(){
        return this->publisher;
    }
    long int Description::getISBN(){
        return this->ISBN;
    }
    void Description::displayBook(){
        cout<< " Book title: "<< this->title<< ", Book Author: "<< this->author
            << ", Book Publisher: "<< this->publisher<< ", Book ISBN : "<< this->ISBN<< " "<< endl;
    }