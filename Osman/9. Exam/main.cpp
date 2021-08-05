#include <iostream>
using namespace std;

int findsum(int n){
    int sum =0;
    for(int i=1; i<=n; i++){
        sum += i;
    }
    return sum;
}

int multipleSum(int n){
    int sum =0;
    int i=0;
    while(sum <= n){
        if(i%3== 0){
            sum += i;
        }
        i++;
    }
    return sum;
}

void print(int n){

    for(int i=0; i< n; i+=2){
        cout<< "*";
    }
    cout<< endl;

}

int main(){
    print(1);
    print(2);
    print(3);

    return 0;
}