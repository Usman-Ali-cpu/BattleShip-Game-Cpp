#include <iostream>
#include <string>
using namespace std;

int main(){
    cout<< "Enter your sentence : ";
    string str;
    getline(cin, str);
    int count = 0;
    int large = 0;


    for(char c: str){
        if(c == ' '){
            if(count > large){
                large = count;
            }
            count = 0;
        }
        count++;
    }
    
    if(count > large){
        large = count-1;
    }
    cout<< "Longest Word Length is " << " - "<< large ;



    return 0;
}