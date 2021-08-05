//3.	Abstract classes and polymorphism                    

//3.1)  Extend the below given class PROPERTY by adding the correct data members given in the constructor.
//      Only derived classes should be able to can change these data members. The program should then run error-free.
//
//3.2)  Modify the class PROPERTY so that it will be an abstract class [by using the member function print()].
//
//3.3)	What�s special about abstract base classes?
//      Answer:We cannot create objects of abstract classes.
//
//
//
//
//3.4)  Extend the program by adding a derived class HOUSE of the abstract class PROPERTY.
//      This class should have the data member floors, which is of the data type int,
//      and furnished, which is of the data type bool, implemented.
//      It�s also supposed to have a default constructor and a constructor member initializer list.
//      Which member function(s) have to be implemented to run the program? Implement this member function(s).


#include <iostream>
#include <string>
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
            return this->town;
        }
        string getStreet(){
            return this->street;
        }
        void setTown(string t){
             this->town= t;
        }
        void setStreet(string s){
             this->street = s;
        }
        float getArea(){
            return this->area;
        }
        void setArea(float a){
            this->area = a;
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
        cout<< "Number of Flours : "<< flours<< endl;
        if(furnished){
            cout<< "Furnished : True"<< endl;
        }
        else {
            cout<< "Furnished : True"<< endl;
        }
        cout<< "Area :" << this->getArea()<< endl;
        cout<< "Street :" << this->getStreet()<< endl;
        cout<< "Town : "<< this->getTown()<< endl;
    }



};





int main()
{
    House h(2, true, "Street #2", "Cap town", 30.56);
    h.print();


    return 0;
}