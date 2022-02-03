#pragma once
#include <iostream>
#include <math.h>
using namespace std;
class Poly
{
private:
	int order;	//Degree of polynomial
	int *coeff; //Pointer to create dynamic array of co-efficients
public:
	Poly();						   //Default constructor
	Poly(int, int);				   //Parameterized Constructor
	Poly(int, int *);			   //Parameterized Constructor
	~Poly();					   //Destructor
	Poly(const Poly &);			   //copy constructor
	Poly &operator=(const Poly &); //Assignment Operator overloading
								   //Mutators and Accessors
	void show();
	void set(int[], int);
	int getOrder() const;
	int *get() const;
	//operator overloading
	Poly operator+(const Poly &);	  //Add two polynomial
	Poly operator-(const Poly &);	  //Substract two polynomial
	Poly operator*(const Poly &);	  //Multiply two polynomial
	Poly operator*(const int);		  //Multiply polynomial with constant
	bool operator==(const Poly &);	  //Check if two polynomial are equal
	const int &operator[](int) const; //Returns nth coefficient
	int &operator[](int n);			  //Returns nth coefficient(lhs)
	int operator()(int);			  //Evaluate P(x) accordingly
	friend ostream &operator<<(ostream &Out, const Poly &);
};
