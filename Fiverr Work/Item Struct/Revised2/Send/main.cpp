#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct Item{
    string name;
    unsigned int value;
    Item(string n, unsigned int v){
        this->name = n;
        this->value = v;
    }
    void display(){
        cout<< "Name : " << this->name << endl;
        cout<< "Value : " << this->value<< endl<< endl;
    }
};

void sort(vector<Item> & s){
    for (int i = 0; i < s.size(); i++){
        int v = s[i].value;
        for (int j = i; j < s.size(); j++){
            if(s[i].value > s[j].value){
                string name = s[i].name;
                s[i].name = s[j].name;
                s[j].name = name;
                s[i].value = s[i].value + s[j].value;
                s[j].value = s[i].value - s[j].value;
                s[i].value = s[i].value - s[j].value;
            }
        }
    }
}

int getSum(vector<Item>& v){
    int sum = 0;
    for (int i = 0; i < v.size(); i++){
        sum += v[i].value;
    }
    return sum;
}

void displayCombi(vector<Item> &v, int reqlen, int start, int current, bool check[], int len){
    if(current > reqlen)
        return;
    else if(current == reqlen){
        cout << "\t{ ";
        for (int i = 0; i < len; i++){
            if(check[i] == true){
                cout<< v[i].name << ":" << v[i].value << ", ";
            }
        }
        cout << " }\n";
        return;
    }
    if(start == len){
        return;
    }
    check[start] = true;
    displayCombi(v, reqlen, start + 1, current + 1, check, len);
    check[start] = false;
    displayCombi(v, reqlen, start + 1, current, check, len);

}

void combinations(int sum,  vector<Item>& local,vector<Item>& A){
    int s = 0;
    int k = 1;
    for (int i = 0; i < A.size()-4; i++){
        local.push_back(A[i]);
        int count = 0;
        for (int j = i+1; j < A.size()-4 ; j++){
            k = j;
            while(count<4){
                local.push_back(A[k]);
                k++;
                count++;
            }
            count = 0;
            s = getSum(local);
            if (s == sum){
                bool c[5] = {false};
                displayCombi(local, 5, 0, 0, c, 5);
            }
            local.clear();
            local.push_back(A[i]);
            s = 0;
        }
        local.clear();
    }
}
int main(){
    vector<Item> vect;
    for (int i = 0; i < 20; i++){
        string s = "name" + to_string(i + 1);
        Item item(s, 25 );
        vect.push_back(item);
    }
    Item ite("namelat", 24);
    vect.push_back(ite);


    int SUM = 124;
    vector<Item> a;
    sort(vect);

    cout << "\n\t*********** WORKING ***********\n" << endl;

    cout << "\n\t*********** RESULTS ***********\n" << endl;

    // Function call
    combinations(SUM, a, vect);

    cout << "\n\t*********** COMPLETED ***********\n" << endl;

    
    




    return 0;
}