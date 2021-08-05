/

// 3. Abstract classes and polymorphism   	(20 points)
//
// 3.1  In the program, add the data members in the class "Property" that match the constructor(s).
//      The data members should only be able to be changed by derived classes. The program should then be able to run without errors.
//
// 3.2  Change the class in the program so that it becomes an abstract base class using the member function print().
//
// 3.3  What is special about abstract base classes? Explain at least three features.
//      Answer:
//	-
//	-
//	-
//
// 3.4  Complete the program with a derived class "House" of the abstract class "Property".
//      This derived class should contain the data member floors, which is of the data type int, and the data member furnished, which is of the data type bool.
//      Create a default constructor and a constructor with member initialization list.
//      Which member function(s) still have to be implemented so that the program can run? Implement this member function(s).

#include <iostream>
using namespace std;

class PROPERTY
{

private:
    float area;
    string town, street;
    static int count;
    public:
        PROPERTY () { count++; }
        PROPERTY (float a, string t, string s): area(a), town(t), street(s) { count++; }
        string getTown(){
            return town;
        }
        string getStreet(){
            return street;
        }
        void setTown(string t){
             town= t;
        }
        void setStreet(string s){
             street = s;
        }
        float getArea(){
            return area;
        }
        void setArea(float a){
            area = a;
        }
        void print() { }; //Output of the data
};

int PROPERTY::count = 0;



class House:public PROPERTY
{
private:
    int flours;
    bool furnished;
public:
    House():flours{1},furnished{true}
    {
        setArea(10);
        setStreet("Unkown Street");
        setTown("Unkown Town");
    }
    House(int flour, bool furnish, string street, string town , float area):flours{1},furnished{true}
    {
        setArea(area);
        setStreet(street);
        setTown(town);
    }
    void print(){
        cout<< "Total Flours : "<< flours<< endl;
        if(furnished = true){
            cout<< "Furnished : True"<< endl;
        }
        else {
            cout<< "Furnished : True"<< endl;
        }
        cout<< "Area :" << getArea()<< endl;
        cout<< "Street :" << getStreet()<< endl;
        cout<< "Town : "<< getTown()<< endl;
    }



};
// 3.3 
// An abstract class is a template definition of methods and variables of a class (​category of objects) 
//      that contains one or more abstracted methods (a method which is undefined in base class);


int main()
{
    House derived(1, false, "Street no 35", "Germany", 90.34);
    derived.print();




    return 0;
}
