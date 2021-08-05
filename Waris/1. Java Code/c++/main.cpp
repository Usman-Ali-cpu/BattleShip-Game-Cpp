#include <iostream>
#include <time.h>
#include <chrono>
#include <ratio> 
#include "TrafficMinimization.cpp"
using namespace std;



int *getArray(int length){
    int *arr=new int[length];
    for(int i=0;i<length;i++){
        srand(time(0));
        arr[i]=(int)( 1 + rand()%100 * length);
    }
    return arr;
}
void print(int array[], int s , int k,TrafficMinimization t){
    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
    long int val= t.performServerplacement(array,s, k);
    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
    long long int timeNano = time_span.count()* pow(10, 9);
    cout << "number of client:" << s << " execution time= "  << timeNano << " ns"<< endl;
    cout<< val << endl;
}

int main(){
    TrafficMinimization t;
    int *ar;
    ar=getArray(10);
    print(ar, 10, 3,t);
    ar=getArray(100);
    print(ar,100, 30,t);
    ar=getArray(100);
    print(ar, 100 ,30,t);
    ar=getArray(500);
    print(ar, 500,30,t);

    return 0;
}