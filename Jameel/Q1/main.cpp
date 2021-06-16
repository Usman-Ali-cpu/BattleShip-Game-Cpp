#include "Pateint.h"
#include "PateintRegister.h"
#include "SubWard.h"
#include "Ward.h"

#include <iostream>
using namespace std;



int main(){



    // PateintRegister pReg;

    // for (int i = 0; i < 3; i++){
    //     cout << "Add Patient ";
    //     pReg.addPateint();
    // }

    // cout << "Remove Patient " << endl;
    // pReg.remove();


    // cout << "\n**************************\n";
    // cout << "\nNumber of Registered Patients is : " << pReg.getNumOfPateint() << endl;
    // cout << "**************************\n";

    // pReg.individualPateint();

    // int registerNum;
    // cout << "Enter Registration Number : ";
    // cin >> registerNum;
    // if(pReg.isRegistered(registerNum)){
    //     cout << "Pateint is Registered " << endl;
    // }
    // else {
    //     cout << "Pateint is not registered " << endl;
    // }

    // cout << "\n**************************\n";
    // pReg.printRegistrations();
    // cout << "**************************\n";


    SubWard wardIn("Cardiology Ward");
    for (int i = 0; i < 2; i++){
        wardIn.addPateint();
    }
    cout << "*************  Ward Name : " << wardIn.getName() << "****************" << endl;
    cout << "Total pateint in Ward " << wardIn.getName() << ":  " << wardIn.getNumOfPateint()<< endl;
    wardIn.individualPateint();

    Ward w("Main Cardiology Ward ");
    w.addWard();
    w.addWard();
    w.printWard();


    return 0;
}