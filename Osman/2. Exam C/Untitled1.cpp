#include<iostream> 
using namespace std;
struct BaseClass{
	const int wheels=2; 
};
struct DerivedClass{
	const int wheels=2;
};
void print(BaseClass &B)
{
	cout<<B.wheels<<endl;
}
int main()
{
	DerivedClass D;
	print(D);
}
