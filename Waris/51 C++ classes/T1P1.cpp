#include <iostream>
using namespace std;

class Poly
{

private:
	int order; //order of the polynomial

	int *coeff; // pointer to array of coeff on the heap

	// size of coeff array predicated on (order + 1)

public:
	Poly()
	{
		order = 0;
		coeff[0] = 1;
	} //default constructor – order=0 & coeff[0] =1

	Poly(int order, int Default = 1)
	{ // creates Nth order poly

		if (order >= Default)
		{

			order = order_;
			coeff = new int[order + 1];
			for (int i = 0; i < order + 1; i++)
			{

				coeff[i] = 0;
			}
		}

		else
		{
			cout << "Invalid Degree." << endl;
			exit;
		}
	}

	Poly(int order, int *coeff)
	{

		if (order >= 1)
		{

			order = order_;
			coeff = new int[order + 1];

			for (int i = 0; i < order + 1; i++)
			{

				coeff[i] = coeff_[i];
			}
		}

		else
		{

			cout << "Invalid Degree";
			exit;
		}

	} //creates an Nth polynomial & inits to the values of an external

	~Poly()
	{

		delete coeff[];

	} // destructor

	Poly(const Poly &rhs) : order(rhs.size()), coeff(new int[rhs.size()])
	{

		for (int i = 0; i < order; i++)
		{

			coeff[i] = rhs.coeff[i];
		}

	} // copy constructor

	Poly &operator=(const Poly &rhs)
	{

		if (this == &rhs)
		{

			return *this;
		}

		else
		{

			delete coeff[];
			coeff = new int[rhs.size()];
			order = rhs.size();

			for (int i = 0; i < order; i++)
			{

				coeff[i] = rhs.coeff[i];
			}
		}

		return *this;

	} //Assignment operator

	//mutators & accessors

	void set(){// Query user for coefficient values);

			   void set(int Coeff[], int size){

				   coeff = Coeff[];

} // input coeffs via external coeff vector

int
getOrder() const
{

	return order;

} // get order of polynomial

int *get() const
{

	return coeff;

} //returns pointer to coeff array
}
;
//overloaded operators

Poly operator+(const Poly &lhs, const Poly &rhs)
{

	Poly add = lhs;
	add += rhs;

	return add;

} // add two polynomials

Poly operator-(const Poly &lhs, const Poly &rhs)
{

	Poly sub = lhs;
	sub -= rhs;
	return sub;

} // subt two polynomials

Poly operator*(const Poly &lhs, const Poly &rhs)
{

	int answer = rhs * lhs;
	return answer;

} // mult two polynomials

Poly operator*(const int scale, Poly &rhs)
{

	Poly sc = rhs;
	sc *= scale;
	return sc;

} // scale a polynomial

Poly operator(const int scale, Poly &rhs);

P2 = scale * P1

	 bool
	 operator==(const Poly &rhs); // equality operator

const int &operator[](int I) const; // return the nth coefficient

int value = P1[](int n); //returns the coeff

int &operator[](int n); // returns the nth coefficient (lhs)

P[n] = Value;

int operator()(int X); // evaluate P(x) according

friend ostream &operator<<(ostream &Out, const Poly &rhs);

//other member functions
}

int main()
{
}
