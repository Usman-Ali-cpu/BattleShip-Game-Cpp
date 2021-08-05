#include <iostream>
using namespace std;

int main(){
    char arr[10];

    for(int i=0; i< 10; i++){
        cout<< "Enter Character number["<< i+1<< "]: ";
        cin>> arr[i];
    }

    int UC= 0, LC=0, NC=0;

    for(int i=0; i< 10; i++){
        if(arr[i]>=65 && arr[i]<=90){
            UC++;
        }
        else if(arr[i]>=97 && arr[i]<=122){
            LC++;
        }
        else {
            NC++;
        }
    }
    cout<< "UC = " << UC<< "   " << "LC = "  << LC<< "    " << "NC = " << NC<< endl;


    return 0;
}