#include <iostream>
#include <string>
using namespace std;

string interlinkem(string s, string t){
    string str;
    int j = 0;
    if(s.length() > t.length()){
        for (int i = s.length()-1 ; i >=0; i--){
            str += s[i];
            if(j<t.length()){
                str += t[j];
            }
            j++;
        }
    }
    return str;
}
string reverses(string s){
    string re;
    for (int i = s.length()-1; i >= 0; i--){
        re += s[i];
    }
    return re;
}

int main(){
    string a, b;
    a = "abcdefg";
    b = "plmk";
    string str= interlinkem(a, b);
    str = reverses(str);
    cout << str;

    return 0;
}