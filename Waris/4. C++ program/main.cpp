#include <iostream> // includeing library for input output operations 
using namespace std;

// here you can see
int doSomething(int *x, int *y){  // pointers in the argument pointing to address of passing variables i.e varibale is x the it would point to &x
    int temp = *x; // derefering the pointer x to get value at the address where pointer is pointing, where temp is declared as temporay variable 
    *x = *y * 10; // again defering the value of x and y pointers and storing value of y multiply by 10 to value of x
    *y = temp * 10; // again defering the value of x and y pointers and storing value of temp multiply by 10 to value of y
    return *x+ *y; // derefering the values of x and y, to get values of pointing address of x and y, and returing after sum
}


int main(){

    int a= 3; // declaring integer variable 
    int b = 5; // declaring integer variable 
    cout<< doSomething(&a, &b); // passing the addresses of x and y
    // while before we were passing varibales
    cout<< a << b;



    return 0;
}