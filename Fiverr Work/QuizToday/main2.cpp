#include <iostream>
#include <fstream>
using namespace std;



int main(){

    char str[100];
    char s[100];
    cout << "Enter a First File: ";
    cin.get(str, 100);
    cin.ignore();
    cout << "Enter a Second File: ";
    cin.get(s, 100);
    cin.ignore();

    ifstream myReadFile;
    myReadFile.open("text1.txt");
    string output;
    if (myReadFile.is_open()) {
        while (!myReadFile.eof()) {
            myReadFile >> output;
            /// cout << output << endl;

            ifstream myReadFile;
            myReadFile.open("text2.txt");
            string second;
            if (myReadFile.is_open()) {
                while (!myReadFile.eof()) {
                    myReadFile >> second;
                    // cout << second << endl;
                    if(output == second){
                        cout<<output<< endl;
                    }
                }
            }
            myReadFile.close();
        }
    }
    myReadFile.close();
    

    return 0;
}