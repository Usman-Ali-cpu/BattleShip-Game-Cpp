

// 4.   Operator overloading            (25 points)
//
// 4.1  Extend the program by an external function, which examines 2 objects for equality.
//      If both objects are the same, i.e. the two numbers are equal, the user should get the output "objects are equal".
//      If the objects are not equal, then the user should get the output "objects are not equal".
//
// 4.2  Extend the program by overloading the opperators istream >> and ostream <<.
//      With istream, the query should be made for number1 and number2.
//      With ostream, both numbers should be printed on the screen.
//
// 4.3  Create two objects of the class Numbers dynamically.
//      The data should be entered by the user (via istream from 4.2).
//      Output the numbers you entered (via ostream from 4.2).
//      Compare the two objects using the external function from 4.1.

#include <iostream>
using namespace std;

class Numbers {
public:
    int number1, number2;
    Numbers(int n1, int n2): number1(n1), number2(n2) {};
    
    friend istream& operator>> (istream& is, Numbers* a);
    friend ostream& operator<< (ostream& os, Numbers* b);
    friend bool operator==(Numbers & n1, Numbers & n2);

};
istream& operator>> (istream& is, Numbers* a){
    cout<< "Enter Number 1: ";
    is>> a->number1;
    cout<< "Enter Number 2: ";
    is>> a->number2;
    return is;

}
bool operator==(Numbers & n1, Numbers & n2){
        if(n1.number1 == n2.number1){
            return true;
        }
        if(n1.number1 != n2.number1){
            return false;
        }
        return true;
}

ostream& operator<< (ostream& os, Numbers *b){
    os<< "Number 1 : "<< b->number1<< endl;
    os<< "Number 2 : "<< b->number2<< endl;
}


int main()
{
    Numbers * n1 = new Numbers(1,2);
    Numbers * n2 = new Numbers(1,2);
    cin>> n1;
    cin>> n2;
    cout<<"Number First : \n"<<  n1;
    cout<<"Number Second : \n"<< n2;

    if(*n1 == *n2){
        cout<< "Objects are Equal "<< endl;
    }
    else {
        cout<< "Objects are not Equal"<< endl;
    }






    return 0;
}
