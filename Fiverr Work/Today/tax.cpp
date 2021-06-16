#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

void getData(double &,char &,int &,double&);
double taxAmount(double,char,int,double);

int main()
{
    double taxableIncome,tax,pensionFundRate;
    char singleOrMarried;
    int childCount=0;
    getData(taxableIncome,singleOrMarried,childCount,pensionFundRate);
    tax=taxAmount(taxableIncome,singleOrMarried,childCount,pensionFundRate);
    cout<<"Tax :$"<<tax<<endl;
    return 0;
}


void getData(double &taxableIncome,char &singleOrMarried,int &childCount,double
&pensionFundRate)
{
    cout<<"Enter the Taxable Income :$";
    cin>>taxableIncome;
    cout<<"Single Or Married (S=Single/M=Married):";
    cin>>singleOrMarried;
    if(singleOrMarried=='m' || singleOrMarried=='M')
    {
        cout<<"Enter No of Children whose age<14 :";
        cin>>childCount;
    }
}





double taxAmount(double taxableIncome,char singleOrMarried,int childCount,double
pensionFundRate)
{
    double tax=0;
    taxableIncome= taxableIncome- taxableIncome* (pensionFundRate / 100);
    
    if(singleOrMarried=='s' ||singleOrMarried=='S'){
        taxableIncome -= 4000;
        taxableIncome -= 1500;
    }
    else{
        taxableIncome-=7000;
        if(childCount!=0)
        {
            taxableIncome-=childCount*1500;
        }
    }
    if(taxableIncome>=0 && taxableIncome<=15000)
    {
        tax=taxableIncome*0.15;
    }
    else if(taxableIncome>=15001 && taxableIncome<=40000)
    {
        tax=2250+(taxableIncome-15000)*0.25;
    }
    else if(taxableIncome>=40000 )
    {
        tax=8460+(taxableIncome-40000)*0.35;
    }
	return tax;
}
