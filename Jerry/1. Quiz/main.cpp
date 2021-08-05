#include <iostream>
#include <time.h>
using namespace std;

int main(){
    int l, h;
    int num;
    cout<< "How many number : ";
    cin>> num;
    cout<< "Enter lower and upper value: ";
    cin>> l>> h;
    int largest =l;
    cout<< "Generated numbers are : ";
    srand((unsigned) time(0));
    for(int i=0; i< num; i++){
        int n = (rand() % h) + l;
        cout<< n << " ";
        if(n > largest){
            largest = n;
        }
    }
    cout<< "\nlargest Number is : "<< largest;
    return 0;
}