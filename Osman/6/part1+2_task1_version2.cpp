
#include <iostream>
using namespace std;

class Candle{
protected:
    int height;
    string color;
public:
    Candle(){
        color = "Unkown"; // defualt value to color member 
        height = 0; // defualt value to height member 
    }
    Candle(string col, int h){
        color = col; // defualt value to color member 
        height = h; // defualt value to height member 
    }
    void data_output()
    {
        cout << "Height  : "<< height<< endl;
        cout << "Colour  : " << color << endl;
    }
    void updateheight()
    {
        int burninghours, burningheight=3, newheight;
        cout<<"For how many hours is burning : ";
        cin>>burninghours;
        newheight = burningheight * burninghours;
        height = height - newheight;

        if(height >0)
            cout<<"Updated height of the candel: "<< height <<endl;
        else
            cout<<"Candle burned down!";
    }
};

int main()
{
    Candle *obj1, *obj2;
    // Since the values of the data members do not have to be queried, 
    // they can be passed as static members.
    // thats why i am passing members as parameter
    obj1 = new Candle("Green", 20); // parameterize constructor is called
    obj2 = new Candle("Brown", 40);  // parameterize constructor is called

    
    //  the member function updateHeight for the first instance.
     cout<< "member function updateHeight for the first instance-> \n";
    obj1->updateheight();
   
    //  Call the member function data_output for the second instance and 
    cout<< "\nData Output for the first instance ->  "<< endl;
    obj2->data_output();



    return 0;
}
