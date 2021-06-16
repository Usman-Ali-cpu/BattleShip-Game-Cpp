
#include <iostream>
using namespace std;


bool isEqual(char *a, char *b){
    int i = 0;
    while(a[i] != '\0'){
        if(a[i] != b[i]){
            return false;
        }
        i++;
    }
    return true;
}

int main()
{
    char str[100];
    char s[100];
    cout << "Enter a string: ";
    cin.get(str, 100);
    cin.ignore();
    cout << "Enter a string: ";
    cin.get(s, 100);
    cin.ignore();
    if(isEqual(str, s)){
        cout << "Equal";
    }
    else {
        cout << "Not equal" << endl;
    }
    return 0;
}