#include <iostream>
#include "BookStore.cpp"
#include <fstream>
using namespace std;

int main(){

    while(true) // loop throgh program 
    {
        cout<< "Purchasing book "<< endl;

        BookStore store("BookStore");
        string title, author, publisher, date;
        long int ISBN, NIF;
        double amount;
    

        cout<< "Enter title of Book : ";
        cin>> title; // asking for title of book
        cout<< "Enter Author of Book : ";
        cin>> author; // asking for author of book
        cout<< "Enter Publisher of Book : ";
        cin>> publisher; // asking for publisher of book
        cout<< "Enter Date of purchase of Book (mm/dd/YYYY) : ";
        cin>> date; // asking for purchase date of book
        cout<< "Enter amount of book : ";
        cin>> amount; // asking for ammount of of book
        cout<< "Enter ISBN of BOOK : ";
        cin>> ISBN; // asking for ISBN of book
        cout<< "Enter NIF of customer : ";
        cin>> NIF; // asking for NIF of cuutomer
        if(!store.isCustomerPresent(NIF)){ // wether customer is already register or not

            // if customer is not registered then 
            string cardNumber;
            long int NIF;
            string phoneNumber;
            string name;
            string address;
            cout<< "Customer is not registered with this ISBN !\n";
            cout<< "Enter NIF of Customer : ";
            cin>> NIF; // asking for NIF of customer
            cout<< "Enter Card Number of customer : ";
            cin>> cardNumber;  // asking forcard number of customer
            cout<< "Enter Phone Number of Customer : ";
            cin>> phoneNumber;  // asking for phone number of customer
            cout<< "Enter Name of Customer : ";
            cin>> name;  // asking for name of customer
            cout<< "Address of Customer : ";
            cin >> address;  // asking for address of customer
            Customer cus(cardNumber,NIF,phoneNumber,name,address);
            store.addCustomer(cus);
        }
        
        Purchase pur(title, author, publisher, ISBN , date, amount);

        store.addPurchase(pur);
        try {
            //open file for writing
            ofstream fw;
            fw.open("purchases.txt", ios::out |ios::app);
            //check if file was successfully opened for writing
            if (fw.is_open())
            {
            //store purchase contents to text file
                fw << date << " ";
                fw << title << " ";
                fw << author << " ";
                fw << publisher << " ";
                fw << ISBN << " ";
                fw << amount << "\n";
                
            }
            else 
                cout << "Problem with opening file";
            fw.close();
        }
        catch (const char* msg) { // catch error if any occurs
            cerr << msg << endl;
        }

        cout<< "Enter 1: To End Purchase "<< endl;
        cout<< "Enter 2: To Continue"<< endl;
        int choice = 0;
        cin >> choice;
        switch (choice) // choice to ending program or not 
        {
            case 1:
            {
                cout<< "Program is Ending "<< endl;
                cout<< "Customers of Store -> \n";
                store.displayCustomer();
                cout<< "\nPurchases of Store -> \n";
                store.displayPurchase();
                exit(0);
            }
            break;
            case 2:
            {
                cout<< "Continue "<< endl;
            }
            break;  
            default:
            {
                cout<< "InValid Choice. So Continue" << endl;
            }
            break;
        }
    }







    return 0;
}