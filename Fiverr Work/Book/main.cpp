#include <iostream>
#include "Book.h"
using namespace std;




int main(){
    int size = 2;  // maximum size of array of book
    Book b(size); 
    string choices;
    char choice;
    
    string title,substr;
    string ID;
    string aisle;
    string bookType;
    int low, high;
    bool flag = true;

    while(flag)  
    {
        
        cout << "Please select an action: " << endl;
        cout << "\t\t a: add a new book" << endl;
        cout << "\t\t d: display book list" << endl;
        cout << "\t\t s: sort the books in descending order based on ID (within a range)" << endl;
        cout << "\t\t n: display the book with the longest amoung the books whose bookType a specific substring" << endl;
        cout << "\t\t q: quit" << endl<< endl << endl;
        cout << "Enter a character : ";
        cin >> choices;
        choice = choices[0];
        switch(choice)
        {
            // case 1 :  to add book to array
            case 'a':
                cout << "Enter title : ";
                cin >> title;
                cout << "Enter ID: ";
                cin >> ID;
                cout << "Enter Aisle : ";
                cin >> aisle;
                cout << "Enter bookType : ";
                cin >> bookType;
                if(b.addBook(title, stoi(ID), stoi(aisle), bookType) == 1){
                    cout << "Book successfully added to the list! " << endl;
                }else{
                    cout << "Error occured in adding book, i.e size is full" << endl;
                }
            break;
            // case 2:  display all the books in array
            case 'd':
                b.display();
            break;
            // case 3: display books in the given range of IDs
            case 's':
                do {
                    cout << "Please enter lower bound of ID: ";
                    cin >> low;
                } while (low < 0);
                do{
                    cout << "Please enter higher bound of ID: ";
                    cin >> high;
                } while (high >= size);
                b.boundSort(low, high);
                break;
            //case 4: find book any substring in booktype

            case 'n':
                cout << "Enter the substring of book's booktype: ";
                cin >> substr;
                b.bookTypeWithString(substr);
                break;
            // case 5: to EXIT the program
            case 'q':
                exit(0);
                flag = false;
                break;
            default:
                cout << "Invalid input try other character!" << endl;
                break;
        }
        system("pause");
        system("cls");
    }

    // b.addBook("title1dgd", 1, 1, "boktypecbhcbec 1");
    // b.addBook("title4d", 4, 4, "boktypesjv 4");
    // b.addBook("title3", 3, 3, "boktypejvjv 3");
    // b.addBook("title2hdsdbf", 2, 2, "boktypend 2");
    
    // b.sort();
    // b.bookTypeWithString("bok");

    return 0;
}