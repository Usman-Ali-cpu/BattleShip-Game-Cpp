#include <iostream>
#include <fstream>
using namespace std;


double dosome(int a, int b){
    int v1= 1, v2=2, v3=1;
    for(int i=a; i< b; i++){
        switch (i)
        {
        case 4:
        case 2:
        case 3:
            v1++;
        case 5:
            v2++;
            break;
        default:
            v3++;

        }
    }
    return (v1+v2)/2*v3;
}


int main(){
    cout<< dosome(-2, 8);
   

    





    return 0;
}