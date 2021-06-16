#include <iostream>
#include "PhoneBook.cpp"
#include "Entry.cpp"
using namespace std;

void compare(PhoneBook &, PhoneBook &);
int main(){

    PhoneBook *book = new PhoneBook[10];
    

    for (int i = 0; i < 10; i++){
        cout << "**********   For PhoneBook# " << i + 1 << " *************\n" << endl;

        for (int j = 0; j < 20; j++){
            cin.ignore();
            cout << "For Entry# " << j + 1 << " -> " << endl;
            Entry e;
            string n, a;
            long int p;
            cout << "Enter your name : ";
            // cin >> n;
            getline(cin, n);
           
            cout << "Enter your Address : ";
            // cin >> a;
            getline(cin, a);
            
            cout << "Enter your Phone Number : ";
            cin >> p;
            e.setValue(n, p, a);
            book[i].add(e);
            cout << endl;
            cin.ignore();
        }
    }
    for (int i = 0; i < 10; i++){
        cout << "\n*********** In PhoneBook# " << i + 1 << " ************ " << endl;
        book[i].Display();
    }

    long int num;
    cout << "Enter PhoneNumber you want to delete: ";
    cin >> num;
    book[1].removeWithPhone(num);

    PhoneBook b = book[1];
    PhoneBook a = book[0];
    compare(a, b);

    PhoneBook c = book[1];
    PhoneBook d = c;
    compare(c, d);

    delete[] book;
    book = NULL;
    return 0;
}


void compare(PhoneBook &a, PhoneBook &b){
    cout << "*************** Comparing PhoneBook Entries ***************** " << endl;
    cout << "It will print True if equal otherwise False "<< endl;
    for (int i = 0; i < 20; i++){
        if(a.getEntry(i) == b.getEntry(i)){
            cout << "Entry#"<< i+1 <<" : True" << endl;
        }
        else{
            cout << "Entry#"<< i+1 <<" : False" << endl;
        }
    }
}