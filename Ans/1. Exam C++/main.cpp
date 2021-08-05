#include <iostream>
using namespace std;


double voltageRange(double voltage, char &volatge_range_ref){
    if(voltage <= 0.4 ){
        volatge_range_ref = 'm';
        return voltage * 1000.0;
    }
    if(voltage > 0.4 && voltage <= 400.0){
        volatge_range_ref = 'V';
        return voltage;
    }
    else {
        volatge_range_ref = 'E';
        return 0.0;
    }
}

int main(){
    char c;
    double vol;
    cout<< "Enter volatge : ";
    cin >>vol;
    cout<< "Return value of volatge Range : " << voltageRange(vol, c)<< endl;
    cout<< "volatge_range_ref: " << c<< endl;




    return 0;
}