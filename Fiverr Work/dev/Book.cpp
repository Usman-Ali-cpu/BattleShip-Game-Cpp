#include <iostream>
#include <string>
#include "Book.h"
using namespace std;


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

