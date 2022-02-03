#include "Poly.h"

int main()
{
	int order = 0, *arr = 0;

	//creating Polynomial
	cout << "Enter the degree of Polynomial : ";
	cin >> order;
	arr = new int[order + 1];
	cout << "Enter the elements " << endl;
	for (int i = 0; i <= order; i++)
	{
		cout << "For x^" << i << " :";
		cin >> arr[i];
	}
	Poly P1(order, arr);
	Poly P2;
	P1.show();
	cout << "Enter the degree of Polynomial : ";
	cin >> order;
	arr = new int[order + 1];
	cout << "Enter the elements " << endl;
	for (int i = 0; i <= order; i++)
	{
		cout << "For x^" << i << " :";
		cin >> arr[i];
	}
	P2.set(arr, order);
	P2.show();
	Poly P3;
	P3 = P1;
	cout << "P3: ";
	P3.show();
	P3 = P1 + P2;
	P3.show();
	P3 = P1 - P2;
	P3.show();
	P3 = P3 * 3;
	P3.show();
	cout << P3;
	P3[2] = 1;
	cout << "P3[2]: " << P3[2] << endl;
	int Z = P3(5);
	cout << "P3(2) = " << Z << endl;
	P3 = P1 * P2;
	cout << P3;
}