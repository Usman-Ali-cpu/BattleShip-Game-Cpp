#include <iostream>
using namespace std;

int main(){
    int liters;
    double price  =0;
    cout<< "Enter the total water comsumption: ";
    cin>> liters;


        if(liters <= 500){
            price = 0.5 * liters;
        }
        else if(liters > 500 && liters <= 1000){
            price = 0.5 * 500 + 0.75 * (liters -500);
        }
        else if(liters > 1000 && liters <= 1500){
            price = 0.5 * 500 + 0.75 * (liters -500) +  0.9 * (liters -1000);
        }
        else {
            price = 0.5 * 500 + 0.75 * (liters -500) +  0.9 * (liters -1000) + 1.5 * (liters -1500);
        }

    cout<< "Water Bill Charge is : "<< price << " Dhs "<< endl;




    return 0;
}