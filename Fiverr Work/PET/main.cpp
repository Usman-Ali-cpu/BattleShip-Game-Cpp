#include <iostream>
#include "Pet.cpp"
using namespace std;



int main(){
    Pet *myPets[2];
    myPets[0] = new Pet("Fluffy", 2);
    myPets[1] = new Pet("Frisky", 4);
    for (int day = 1; day <= 9; day++){
    cout << "======== Day" << day << endl;
        for (int k = 0; k < 2; k++){
            careFor(myPets[k], day);
        }
    }
    cout << "=============" << endl;
    for (int k = 0; k < 2; k++){
        if(myPets[k]->alive()){
            cout << "Animal Control has come to rescue "
                 << myPets[k]->getname() << endl;
        }
        delete myPets[k];
    }
    return 0;
}