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
void swap(vector<Item>& v, int i, int j){
    if(j>4){
        j = 0;
    }
    string name = v[i].name;
    v[i].name = v[j].name;
    v[j].name = name;
    v[i].value = v[i].value + v[j].value;
    v[j].value = v[i].value - v[j].value;
    v[i].value = v[i].value - v[j].value;

}
bool ifExists(vector<Item> &v , Item a){
    int j = 0;
    for (int i = 0; i < 5; i++){
        // cout << v[i].name << " " << a.name << endl;
        if(v[i].name == a.name){
            j++;
        }
    }
    if(j>=2){
        return true;
    }
    return false;
}
void printvect(vector<Item> &v){
    for (int i = 0; i < 5; i++){
        if(ifExists(v, v[i])){
            return;
        }
    }
        cout << "\t{ ";
        for (int i = 0; i < 5; i++){
            cout<< v[i].name << ":" << v[i].value << ", ";
        }
        cout << " } " << getSum(v) << " \n";
}

void replace(vector<Item> &v, Item& A){
    for (int i = 0; i < v.size(); i++){
        if(A.value == v[i].value){
            v[i] = A;
            return;
        }
    }
}

void display(vector<Item> &v,vector<Item>& A ){
    printvect(v);
    for (int i = 0; i < 5;i++){
        Item it = v[i];
        for (int j = 0; j < A.size(); j++){      
            if(v[i].value == A[j].value && v[i].name != A[j].name){
                replace(v, A[j]);
                printvect(v);
            }
        }
    }
}



void combinations(int sum,  vector<Item>& local,vector<Item>& A){
    int counter = 0;
    int s = 0;
    int k = 1;
    for (int i = 0; i < A.size(); i++){
        if(i>= A.size()){
            i = 0;
        }
        if(i<A.size())
        {
            local.push_back(A[i]);
            int count = 0;
            for (int j = i+1; j < A.size() ; j++){
                if(j>= A.size()){
                    j = 0;
                }
                if(j< A.size())
                {
                    k = j;
                    while(count<4){
                        if(k>= A.size()){
                            k = 0;
                        }
                        if(k < A.size()){
                            local.push_back(A[k]);
                            k++;
                        }
                        count++;
                    }
                    count = 0;
                    s = getSum(local);

                    // if (s == sum){
                        bool c[5] = {false};
                        display(local, A);
                        counter++;
                        // }
                        local.clear();
                        local.push_back(A[i]);
                        s = 0;
                }
            }
            local.clear();
        }
    }
    cout << "Cunter is : " << counter << endl;
}
int main(){
    vector<Item> vect;
    vect.push_back({"name1", 1});
    vect.push_back({ "name2", 2});
    vect.push_back({ "name3", 3});
    vect.push_back({ "name4", 4});
    vect.push_back({ "name5", 5});
    vect.push_back({ "name6", 6});
    vect.push_back({ "name7", 7});

    vect.push_back({ "name8", 8});
    vect.push_back({ "name9", 9});
    // vect.push_back({ "name10", 10});
    
    // for (int i = 0; i < 24; i++){
    //     string s = "name" + to_string(i + 1);
    //     Item item(s, i );
    //     vect.push_back(item);
    // }
    // Item ite("namelat", 24);
    // vect.push_back(ite);


    int SUM = 227;
    vector<Item> a;

    cout << "\n\t*********** WORKING ***********\n" << endl;

    cout << "\n\t*********** RESULTS ***********\n" << endl;

    // Function call
    combinations(SUM, a, vect);

    cout << "\n\t*********** COMPLETED ***********\n" << endl;

    return 0;
}