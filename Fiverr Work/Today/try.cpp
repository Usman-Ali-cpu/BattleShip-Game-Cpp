#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;


int main(){
	double taxableIncome = 999999;
	double get = taxableIncome * (6.0 / 100);
	taxableIncome -= get;
	cout<<taxableIncome;
	return 0;
}
