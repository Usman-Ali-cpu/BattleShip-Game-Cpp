#include <iostream>
using namespace std;

bool RemoveFirstOccurance(int a[], int& length_ref, int x){
    bool isfound= false;
    for(int i=0; i< length_ref; i++){
        if(x == a[i]){
            // cout<< "foudn true ";
            isfound = true;
            break;
        }
    }
    if(!isfound){
        cout<< "Elenent ";
        return false;
    }
    else {
        if(a[length_ref-1] == x){
            length_ref--;
            return true;
        }
        else {
            for(int i=0; i< length_ref; i++){
                if(x == a[i]){
                    int t = a[length_ref-1];
                    a[length_ref-1] = x;
                    a[i] = t;
                }
            }
            length_ref--;
            return true;
        }
    }
}

int main(){
    int s;
    int rele;
    cout<< "Enter size of array: ";
    cin>> s;
    int *a = new int[s];
    for(int i=0; i< s; i++){
        cout<< "Enter array element (int type) a["<< i<< "] : ";
        cin>> a[i];
    }
    cout<< "Enter element to remove : " ;
    cin>> rele;

        cout<< "RemoveFirstOccurance () with return value " <<  RemoveFirstOccurance(a, s, rele)<< endl;
        cout<< "Array element with first occurance of " << rele<< " removed "<< endl;
        for(int i=0; i< s; i++){
            cout<< "a["<< i<< "] = "<< a[i] << ", ";
        }
    
    return 0;
}