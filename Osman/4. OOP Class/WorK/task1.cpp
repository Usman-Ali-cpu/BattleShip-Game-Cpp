//1.	Dynamic objects                

//1.1)	Declare a class named CANDLE with the following data members
//      Height (in cm) and colour. Choose appropiate data types.
//      These data members can only be changed by derived classes.
//      Define for the class:
//      a) Standard constructor
//      b) Parameterized constructor with member initialization list
//      c) Member function data_output for the output of all data. The member function data_output should be defined outside of the class.
//
//1.2)  From experience, you know that a candle loses an average of 3 cm per hour of its Height.
//
//      Define a member function named updateHeight with the parameter burningHours and a suitable data type.
//      The member function has the task to update the Height of the candle based on the hours.
//      If the candle burned down after the update, the user should get an appropriate message,
//      otherwise the program will print the current height of the candle.
//
//1.3)  Create 2 dynamic objects of the class CANDLE.
//      Since the values of the data members do not have to be queried, they can be passed as static members.
//      Call the member function data_output for the second instance and the member function updateHeight for the first instance.




#include <iostream>
#include <string>
using namespace std;


class CANDLE
{
private:
    int height; // private data member for height
    string colour; // private data member for colour

public:
    // standardconstructor() {}    ***** standard constructor is not called like this *****

    // a) this is standard constructor. it is also called as defualt constructor
    CANDLE(); // Standard constructor 

    // b) this is parameterize constructor , it is initializing values by passing values
    CANDLE(string col, int h); // parameterize constructor


    // c) Member function data_output for the output of all data. 
    // The member function data_output should be defined outside of the class.

    void setHeight(int h); // setter for height 
    void setColour(string c); // setter for colour 
    int getHeight(); // getter for height
    string getColour(); // getter for colour 

    // 1.2)  From experience, you know that a candle loses an average of 3 cm per hour of its Height.
    void updateheight(); // for unpdating height

    // Member function data_output for the output of all data.
    void data_output();
};

CANDLE::CANDLE(){
        this->colour = "Unkown"; // defualt value to color member 
        this->height = 0; // defualt value to height member 
}
CANDLE::CANDLE(string col, int h){
        this->colour = col; // defualt value to color member 
        this->height = h; // defualt value to height member 
}
void CANDLE::setHeight(int h){
        this->height = h;
}
void CANDLE::setColour(string c){
        this->colour = c;
}
int CANDLE::getHeight(){
        return this->height;
}
string CANDLE::getColour(){
    return this->colour;
}
void CANDLE::data_output()
{
    cout << "Height of Candle : "<< this->getHeight()<< endl;
    cout << "Colour of Candle : " << this->getColour()<< endl;
}

void CANDLE::updateheight()
{
    int burninghours, height=3, newheight;
    cout<<"For how many hours is burning : ";
    cin>>burninghours;
    newheight = height * burninghours;
    this->height = this->getHeight() - newheight;

    if(this->getHeight() >0)
        cout<<"This is the updated height of the candel: "<< this->getHeight() <<endl;
    else
        cout<<"Candle burned down!";
}

int main()
{
    // 1.3)  Create 2 dynamic objects of the class CANDLE

    // first of all you always need to make objects in main.


    CANDLE *dynamicobj1, *dynamicobj2;
    // Since the values of the data members do not have to be queried, 
    // they can be passed as static members.
    // thats why i am passing members as parameter
    dynamicobj1 = new CANDLE("Blue", 20); // parameterize constructor is called
    dynamicobj2 = new CANDLE("Yellow", 30);  // parameterize constructor is called

    
     //  the member function updateHeight for the first instance.
     cout<< "member function updateHeight for the first instance-> \n";
    dynamicobj1->updateheight();
   
    //  Call the member function data_output for the second instance and 
    cout<< "\nData Output for the first instance ->  "<< endl;
    dynamicobj2->data_output();

    return 0;
}