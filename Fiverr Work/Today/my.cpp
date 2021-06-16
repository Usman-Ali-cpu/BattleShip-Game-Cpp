#include <iostream>
#include <iomanip>
using namespace std;

const double MARRIED_DEDUCTION = 7000.00;    // Declare constant double to store deduction for married 
const double SINGLE_DEDUCTION = 4000.00;     // Declare constant double to store deduction for single
const double PERSONAL_EXECPTION = 1500.00;   // Declare constant double to store deduction for each Person when married 

// function's prototypes
void getData(double &,char &,int &,double &);  
double checkTaxRate(double & taxableIncome);
double taxAmount(double,char ,int ,double);

int main(){
    char maritalStatus;  // charactor declartion for martial Status 
    int noOfChild;       // int to store number of childs
    double grossSalary =0.0 , percentSalary =0.0, tax=0.0; // some double variables intialization 
    getData(grossSalary,maritalStatus,noOfChild,percentSalary);  // this function will take input from user which are appropiate
    tax=taxAmount(grossSalary,maritalStatus,noOfChild,percentSalary);  // this function will return tax
    cout <<fixed<<  setprecision(2)<< "Your tax for this year is : " << tax << endl;  // display tax 

    return 0;
}

double taxAmount(double taxableIncome,char singleOrMarried,int childCount,double
pensionFundRate)
{
	 double taxable = 0.0,tax = 0.0, sumStandardExem=0.00;
	taxable = taxableIncome* (pensionFundRate * 0.01);  // this is ammount contributed to pension plan 
	
	// it will check if maritialStatus is single or married 
	if(singleOrMarried=='s' ||singleOrMarried=='S'){
    	sumStandardExem = SINGLE_DEDUCTION + PERSONAL_EXECPTION + taxable;  
		//  it will calculate sum of standard exemptions, it is sum of 
    	// single deduction, personal execption, and ammount contributed to pension plan
        taxableIncome -= sumStandardExem; // it is taxable income for single person 
    }
    // it will check if maritialStatus is single or married 
    else if(singleOrMarried=='m' ||singleOrMarried=='M'){
    	// sum of standard execption is  =  married decduction, ammount contributed to pension plan and 
		//  personal execption where it is multiply py member in family lile ,
		// if have 4 chlid then total members will six =  3 child + 1 husband + 1 wife = 6 
		// thats why we add 2 to childcount as a husband and wife 
        sumStandardExem = MARRIED_DEDUCTION + taxable;    
        sumStandardExem += (childCount+2) *PERSONAL_EXECPTION;  // it is final sum of standard execption
        taxableIncome -= sumStandardExem;  //  it is taxable income for single person
    }
    tax = checkTaxRate(taxableIncome);  // it will check tax rate of taxable income 
    return tax;  // returning tax 
} 
double checkTaxRate(double & taxableIncome){
	double tax = 0.00;
	if(taxableIncome>=0 && taxableIncome<=15000) // check taxableIncome in that range 
    {
        tax=taxableIncome*0.15; // calculate tax  for this range
    }
    else if(taxableIncome>=15001 && taxableIncome<=40000)   // check taxableIncome in that range 
    {
        tax=2250+(taxableIncome-15000)*0.25; // calculate tax  for this range
    }
    else if(taxableIncome>=40000 )  // check taxableIncome in that range 
    {
        tax=8460+(taxableIncome-40000)*0.35; // calculate tax  for this range
    }
	return tax;
}

// passing all variables by reference because there value would be change 
void getData(double &taxIncome,char &martialStatus,int &childCount,double &pensionFundRate)
{
	
	cout << "Enter martial status: m or M (married), s or S (single): ";
    cin>>martialStatus;  // get character 
    if(martialStatus=='m' || martialStatus=='M'){
        cout << "\nEnter number of childern under the age of 14: ";
        cin>>childCount;  // get number of childern
        while(childCount <0){  // number of childern cannot be negative 
        	cout << "\nEnter number of childern under the age of 14: ";
        	cin>>childCount;	  
		}
    }
    cout << "\nEnter gross salary for the year: ";
    cin>>taxIncome;  // grosss salary
    do{
    	cout << "\nEnter precentage of salary contributed to pension (0-6 percent): ";
    	cin>> pensionFundRate;	 // get fund rate of pension 
	}while(pensionFundRate>6 || pensionFundRate<0); // fund rate of pension cannot be less than 0 and greater than 6
}
