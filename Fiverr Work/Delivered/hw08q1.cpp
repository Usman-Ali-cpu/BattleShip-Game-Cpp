#include <iostream>
#include "Book.cpp"
using namespace std;


// input function to take input for book data
void input(string &t, string & id, string &a, string &type){
    cout << "Enter title : ";
    getline(cin, t);
    cout << "Enter digit ID: ";
    getline(cin,id);
    // exeptional handling would check whether id entered by user is integer digit or alphabets
    try 
    {
        int i = 0;
        i = stoi(id);
    }
    // if id is alphabets then it would give another chance to enter digit id.
    catch(const std::exception& e)
    {
        cout << "Not valid ID! " << endl;
        cout << "One last chance!\n Enter digits (not alphabets) ID: ";
        getline(cin,id);
        try{
            int j = stoi(id);
        }
        // if id is again not integer then program will terminate.
        catch(const std::exception& e){
            cout << "Program is going to terminate" << endl;
            system("pause");
            exit(0);
        }
        
    }

    cout << "Enter digit Aisle : ";
    getline(cin, a);
    // exeptional handling would check whether aisle entered by user is integer digit or alphabets
    try
    {
        int i = 0;
        i = stoi(a);
    }
    // if aisle is alphabets then it would give another chance to enter digit id.
    catch(const std::exception& e)
    {
        cout << "Not valid Aisle! " << endl;
        cout << "One last chance!\nEnter digits (not alphabets) aisle : ";
        getline(cin,a);
        try{
            int j = stoi(id);
        }
        // if aisle is again not integer then program will terminate.
        catch(const std::exception& e){
            cout << "Program is going to terminate" << endl;
            system("pause");
            exit(0);
        }
    }

    cout << "Enter bookType : ";
    getline(cin, type);
}

int main(){
    int size = 5;  // maximum size of array of book
    Book b(size);  // array of book of given size
    // string choices;
    char choice = 'a';
    string title = "";
    string substr;
    string ID = " ";
    string aisle = " ";
    string bookType = " ";
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
        choice = getchar();
        cin.ignore();
        // choice = choices[0];
        switch(choice)
        {
            // case 1 :  to add book to array
            case 'a':
            {
                input(title, ID, aisle, bookType);
                if(b.addBook(title, stoi(ID), stoi(aisle), bookType) == 1){
                    cout << "Book successfully added to the list! " << endl;
                }else{
                    cout << "Error occured in adding book, i.e Size is full / (title or ID already exist)" << endl;
                }
            }
            break;
            // case 2:  display all the books in array
            case 'd':
            {
                b.display();
            }
            break;
            // case 3: display books in the given range of IDs
            case 's':
            {
                do {
                    cout << "Please enter lower bound of ID: (greater the 0) ";
                    cin >> low;
                } while (low < 0);
                do{
                    cout << "Please enter higher bound of ID: (less than eqaul to size) ";
                    cin >> high;
                } while (high > size);
                b.boundSort(low, high);
            }
            break;
            //case 4: find book any substring in booktype

            case 'n':
            {
                cout << "Enter the substring of book's booktype: ";
                getline(cin,substr);
                b.bookTypeWithString(substr);
            }
                break;
            // case 5: to EXIT the program
            case 'q':
            {
                cout << "******  Program Gone End *******" << endl;
                exit(0);
                flag = false;
            }
                break;
            default:
                cout << "Invalid input try other character!" << endl;
                break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}