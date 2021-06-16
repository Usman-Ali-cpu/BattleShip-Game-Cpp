#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main()
{
	srand(time(0));
	
	for(int i=0;i<10;i++)
	{
		int num=rand()%10;
		int sum=0;
		for(int j=0;j<=num;j++)
		{
			sum+=j;
		}
		cout<<"Generated Number: "<<num<<"\t";
		cout<<"The sum of numbers between 1 and "<<num<< " is "<<sum<<endl;
	}
	
	return 0;
}