#include <iostream>
using namespace std;

int main(){
    float arr[10];
    cout<< "Enter Sequence of 10 numbers : ";
    for(int i=0; i< 10; i++){
        cin>> arr[i];
    }
    float min = 2345435;
    for(int i=0; i< 10; i++){
        if(arr[i]< min){
            min = arr[i];
        }
    }
    cout<< "The min value in the input is : "<< min<< endl;
    cout<< "Number \t Number-max"<< endl;
    for(int i=0; i< 10; i++){
        cout<< arr[i] << "\t"<< arr[i]-min << endl;
    }
    return 0;
}