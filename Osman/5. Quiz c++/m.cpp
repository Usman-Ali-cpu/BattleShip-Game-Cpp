#include <iostream>
using namespace std;
int main(){
    int distance, sum =0, count =0, i=0, jump ;
    cout<< "How much distance to cover : ";
    cin>> distance;
    cout<< "how much can it jump : ";
    cin>> jump;
    while(sum< distance){
        sum += jump++;
        cout<< "After Jump# " << i+1<< " : " << sum<< endl;
        count++;
    }
    cout<< "Total Jump : "<< count;
    return 0;
}