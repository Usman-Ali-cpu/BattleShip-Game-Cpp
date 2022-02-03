#include <iostream>
using namespace std;


void guess(int a, int b, int&c, int &d){
    c = a;
    for(int i=2; i<=a; i++){
        c = c*i;
    }
    d =0;
    for(int i=2; i< b; i++){
        if(b%i==0){
            d++;
        }
    }
}
void get(int a, int b, int &c){
    if(a>b){
        a = b;
    }
    else 
        b = a;
    if((a+b) > c){
        c = a+ b;
    }
    else 
        c = 2 * a+b;
}


int main(){
    int x1=3, x2=4, x3=7;
    get(x1,x2,x3);
    cout<< x1<< " " << x2<< " "<< x3;
    


    return 0;
}