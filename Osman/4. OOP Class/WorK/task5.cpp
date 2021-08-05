//5.	Operator overloading, error handling								
//      Below you will see a class CALCULATOR which has a private data member num of type float.
// 	    It's also declaring the operator overloading functions for input/output and some arithmetic operands.
// 	    In the main function, the user can type in the value 1-4 and perform a calculation by using two objects of type CALCULATOR.
//
// 	    Complete the Definition of the operator overloading functions outside of the class!
// 5.1) For operator>>, the function should let the user type in the value for the data member num, so that the value will be stored in the data member num of the passed object.
// 5.2) For operator<<, the function should output the value of the data member num of the passed object.
// 5.3) For operator+, the function should return an object of type CALCULATOR, where the data member num holds the value of the addition of the two passed objects.
// 5.4) For operator-, the function should return an object of type CALCULATOR, where the data member num holds the value of the subtraction of the two passed objects.
// 5.5) For operator*, the function should return an object of type CALCULATOR, where the data member num holds the value of the multiplication of the two passed objects.
// 5.6) For operator/, the function should return an object of type CALCULATOR, where the data member num holds the value of the division of the two passed objects.
//	    Dividing by 0 should not be possible! Use a try-catch-block to prevent division by zero. If this happens, throw an error and set the value of num to 0.
// 5.7) What's the purpose of using friend?
//	    Answer:
#include <iostream>
#include <string>
using namespace std;


class CALCULATOR {
    private:
        float num;
    public:
        CALCULATOR(): num(0) {}
        void setNum(int n){
            num = n;
        }
        int getNum(){
            return this->num;
        }

        // Declaring operator overloading functions for calculation
        CALCULATOR operator+ (CALCULATOR);
        CALCULATOR operator- (CALCULATOR);
        CALCULATOR operator* (CALCULATOR);
        CALCULATOR operator/ (CALCULATOR);
        // Declaring input/output functions as friend of the class
        friend istream& operator>> (istream& is, CALCULATOR& a);
        friend ostream& operator<< (ostream& os,  CALCULATOR& b);
};


CALCULATOR CALCULATOR::operator+ (CALCULATOR c){
    int num = this->getNum() + c.getNum();
    CALCULATOR cal;
    cal.setNum(num);
    return cal;
}
CALCULATOR CALCULATOR::operator- (CALCULATOR c){
    int num = this->getNum() - c.getNum();
    CALCULATOR cal;
    cal.setNum(num);
    return cal;

}
CALCULATOR CALCULATOR::operator* (CALCULATOR c){
    int num = this->getNum() * c.getNum();
    CALCULATOR cal;
    cal.setNum(num);
    return cal;

}
CALCULATOR CALCULATOR::operator/ (CALCULATOR c){
    int num = this->getNum() / c.getNum();
    CALCULATOR cal;
    cal.setNum(num);
    return cal;

}

istream& operator>> (istream& is, CALCULATOR& a){
    cout<< "Enter Number : ";
    is>> a.num;
    return is;
}
ostream& operator<< (ostream& os,  CALCULATOR& b){
    os << "Number is : "<< b.getNum()<< endl;
    return  os;
}




int main()
{
    unsigned short choice;
    CALCULATOR obj1, obj2, result;

    do{
        system("cls"); // Delete this line, if it doesn't work for you (in Linux)
        cout << "CALCULATOR:\n"
        << "What would you like to do? Please input the following number:\n"
        << "[1]\tAdd\n"
        << "[2]\tSubtract\n"
        << "[3]\tMultiply\n"
        << "[4]\tDivide\n"
        << "[0]\tTerminate application\n";
        cin >> choice;

        switch(choice){
            case 1:
                cin >> obj1;
                cin >> obj2;
                result = obj1 + obj2;
                cout << result;
                system("pause"); // Delete this line, if it doesn't work for you (in Linux)
                break;
            case 2:
                cin >> obj1;
                cin >> obj2;
                result = obj1 - obj2;
                cout << result;
                system("pause"); // Delete this line, if it doesn't work for you (in Linux)
                break;
            case 3:
                cin >> obj1;
                cin >> obj2;
                result = obj1 * obj2;
                cout << result;
                system("pause"); // Delete this line, if it doesn't work for you (in Linux)
                break;
            case 4:
                cin >> obj1;
                cin >> obj2;
                result = obj1 / obj2;
                cout << result;
                system("pause"); // Delete this line, if it doesn't work for you (in Linux)
                break;
            case 0:
                cout << "Application terminating...\n";
                break;
            default:
                cout << "Invalid choice! " << endl;
                system("pause"); // Delete this line, if it doesn't work for you (in Linux)
		}

	}while(choice!=0);

	return 0;
}
