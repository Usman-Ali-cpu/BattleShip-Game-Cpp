#include <iostream>
using namespace std;



double modlateVoltage(int t_in, int t_out, double vcc){
    double num = t_in * vcc;
    double den = t_in + t_out;
    
    return num/den;
}

int main(){
    int in, out;
    double vcc;

    cout<< "Enter value for t_in: ";
    cin>> in;
    cout<< "Enter value for t_out: ";
    cin>>out;
    cout<< "Enter value for vcc: ";
    cin>> vcc;


    cout<< "return value of  modlateVoltage() is : "<< modlateVoltage(in, out, vcc);


    

    return 0;
}