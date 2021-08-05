#include <iostream>
#include <string>
using namespace std;

int main(){
    char str[80];

    cout<< "Enter line of text : ";
    cin.getline(str, 80);

    char ch;
    int count =0;
    cout<< "Enter a character to search for : ";
    cin>> ch;

    cout<< "Characters are in locations: ";
    for(int i=0; i< 80; i++){
        if(ch == str[i]){
            cout<< i << " ";
            count++;
        }
    }
    cout<< "\nNumber of locations : " << count << endl;

    return 0;
}