#include <iostream>
#include "Account.h"        // adding Account base class 
#include "AccountType.h"    // adding AccountType drived class
using namespace std;



int main()
{
    AccountType saving;     // calling an object of AccountType
    saving.input();         // this member function would take input in deposits
    AccountType current;    // calling an object of AccountType for current account
    current = saving;       // assignment operator calling 
    current.setInterestRate(0.09);      // giving interest rate for cuurent account 
    int j = 5;
    cout << "\n For current Account \n"; 
    for (int i = 0; i < 5; i++, j--){
        cout << "Enter the "<< i+1 <<"th deposit: (this will be invested for" <<j << "years):  "; 
        cin >> current[i];  // input into deposit by calling operator[]
    }
    cout << "Saving Account Statement -> " << endl;
    saving.displayAmount();   // display accumulated of saving account
    cout << "Current Account Statement -> " << endl; // display accumulated of current account
    current.displayAmount();  // display accumulated of current account

        return 0;
}

































/*

class SavingAcc: public Account{
    double interestRate;
    int *savingInterest;

public:
    SavingAcc(){
        size = 5;
        savingInterest = new int[size];
        interestRate = 0.19;
        for (int i = 0; i < size; i++){
            savingInterest[i] = 0;
        }
    }
    SavingAcc &copy(SavingAcc & saving){
        size = saving.size;
        this->accumlator = saving.accumlator;
        this->interestRate = saving.interestRate;
        this->deposit = saving.deposit;
        this->savingInterest = saving.savingInterest;

        for (int i = 0; i < size; i++){
            this->accumlator[i] = saving.accumlator[i];
            this->deposit[i] = saving.deposit[i];
            this->savingInterest[i] = saving.savingInterest[i];
        }
        return *this;
    }
    SavingAcc &operator=(SavingAcc & saving){
        size = saving.size;
        this->accumlator = saving.accumlator;
        this->interestRate = saving.interestRate;
        this->deposit = saving.deposit;
        this->savingInterest = saving.savingInterest;

        for (int i = 0; i < size; i++){
            this->accumlator[i] = saving.accumlator[i];
            this->deposit[i] = saving.deposit[i];
            this->savingInterest[i] = saving.savingInterest[i];
        }
        return *this;
    }

    void calculateInterest(){
        int j = size;
        for (int i = 0; i < size; i++){
            savingInterest[i] = ( PRINCIPAL  * (1 + interestRate) * i+1 ) - PRINCIPAL ;
        }
    }
    void displayAmount(){
        calculateInterest();
        for (int i = 0; i < size; i++){
            cout << "Accumulated deposit+interest after the year "<< i+1 <<": $ " << accumlator[i] + savingInterest[i]<< endl;
        }
    }
    ~SavingAcc(){
        delete[] savingInterest;
        savingInterest = NULL;
    }
};

class CheckingAcc: Account{
    int *accumlator;
    int size;
    double interestRate;
    int *checkingInterest;

public:
    CheckingAcc(){
        size = 5;
        accumlator = new int[size];
        interestRate = 0.09;
        for (int i = 0; i < size; i++){
            accumlator[i] = deposit[i];
        }
        for (int i = 0; i < size; i++){
            checkingInterest[i] = 0;
        }
    }
    CheckingAcc &copy(CheckingAcc & checking){
       size = checking.size;
        this->accumlator = checking.accumlator;
        this->interestRate = checking.interestRate;
        this->deposit = checking.deposit;
        this->checkingInterest = checking.checkingInterest;

        for (int i = 0; i < size; i++){
            this->accumlator[i] = checking.accumlator[i];
            this->deposit[i] = checking.deposit[i];
            this->checkingInterest[i] = checking.checkingInterest[i];
        }
        return *this;
    }
    CheckingAcc &operator=(CheckingAcc & checking){
        size = checking.size;
        this->accumlator = checking.accumlator;
        this->interestRate = checking.interestRate;
        this->deposit = checking.deposit;
        this->checkingInterest = checking.checkingInterest;

        for (int i = 0; i < size; i++){
            this->accumlator[i] = checking.accumlator[i];
            this->deposit[i] = checking.deposit[i];
            this->checkingInterest[i] = checking.checkingInterest[i];
        }
        return *this;
    }
    int & operator[](int i){
        return deposit[i];
    }
    void calculateInterest(){
        int j = size;
        for (int i = 0; i < size; i++){
            checkingInterest[i] = PRINCIPAL* ( (1 + interestRate) * j) - PRINCIPAL ;
            j--;
        }
    }
    ~CheckingAcc(){
        for (int i = 0; i < size; i++){
            accumlator[i] = 0;
        }
        delete[] accumlator;
        accumlator = NULL;
    }

};
class MoneyMarketAcc: Account{
    int *accumlator;
    int size;
    double interestRate;
    int *marketingInterest;

public:
    MoneyMarketAcc(){
        size = 5;
        accumlator = new int[size];
        interestRate = 0.04;
        for (int i = 0; i < size; i++){
            accumlator[i] = deposit[i];
        }
        for (int i = 0; i < size; i++){
            marketingInterest[i] = 0;
        }
    }
    MoneyMarketAcc &copy(MoneyMarketAcc & marketing){
        size = marketing.size;
        this->accumlator = marketing.accumlator;
        this->interestRate = marketing.interestRate;

        for (int i = 0; i < size; i++){
            this->accumlator[i] = marketing.accumlator[i];
        }
        return *this;
    }
    MoneyMarketAcc &operator=(MoneyMarketAcc & marketing){
        this->size = marketing.size;
        this->accumlator = marketing.accumlator;
        this->interestRate = marketing.interestRate;

        for (int i = 0; i < size; i++){
            this->accumlator[i] = marketing.accumlator[i];
        }
        return *this;
    }
    int & operator[](int i){
        return deposit[i];
    }
    void calculateInterest(){
        int j = size;
        for (int i = 0; i < size; i++){
            marketingInterest[i] = PRINCIPAL* ( (1 + interestRate) * j) - PRINCIPAL ;
            j--;
        }
    }
    ~MoneyMarketAcc(){
        for (int i = 0; i < size; i++){
            accumlator[i] = 0;
        }
        delete[] accumlator;
        accumlator = NULL;

        delete[] marketingInterest;
        marketingInterest = NULL;
    }

};

*/
