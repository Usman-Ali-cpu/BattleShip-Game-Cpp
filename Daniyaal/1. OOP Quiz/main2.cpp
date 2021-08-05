#include <iostream>
using namespace std;

int main(){
    int n;
    cout<< "How many Uppercase letter: ";
    cin>> n;
    string str;
    cout<< "Enter " << n<< " uppercase letter: ";
    cin >> str;

    char ch = str.at(0);

    
    int count =0;
    for(int i=0; i< n; i++){
        if(ch != str.at(i)){
            
            while(ch != str.at(i+1)){
                ch++;
                count++;
            }
        }
        else{
            ch++;
        }
    }
    cout<< "There are " << count-1 << " missing letter(s) ";





    return 0;
}