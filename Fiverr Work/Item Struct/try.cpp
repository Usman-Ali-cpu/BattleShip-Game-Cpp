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
void display(vector<Item> &v){
    cout << "{ ";
    for (int i = 0; i < v.size(); i++){
        cout << v[i].name << ":" << v[i].value << ", ";
    }
    cout << " }";
    cout << endl<< endl;
}

void combinations(int sum,  vector<Item>& local,vector<Item>& A){
    int s = 0;
    int k = 1;
    for (int i = 0; i < A.size()-4; i++){
        local.push_back(A[i]);
        int count = 0;
        for (int j = i+1; j < A.size()-4 ; j++){
            // cout << " ********* **********" << endl;
            k = j;
            // cout << "J : " << j << endl;
            // cout << "Pushing : " << A[i].value << endl;
            while(count<4){
                local.push_back(A[k]);
                // cout << "Pushing : " << A[k].value << endl;
                k++;
                count++;
            }
            count = 0;
            // cout << "k : " << k << endl;
            // display(local);
            s = getSum(local);
            // cout << "Sum " << i << " : " << s << endl;
            if (s == sum){
                // cout << "******  Start *****" << endl;
                display(local);
                // cout << "****** END *****" << endl;
            }
            //cout << "Local size : " << local.size() << endl;
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
        Item item(s, 50 );
        vect.push_back(item);
    }
    Item ite("namelat", 24);
    vect.push_back(ite);


    int SUM = 250;
    vector<Item> a;
    sort(vect);

    cout << "\n\t*********** WORKING ***********\n" << endl;

    cout << "\n\t*********** RESULTS ***********\n" << endl;

    // Function call
    combinations(SUM, a, vect);

    cout << "\n\t*********** COMPLETED ***********\n" << endl;

    
    




    return 0;
}