#include "Poly.h"
#include <math.h>
Poly::Poly()
{
	order = 0;
	coeff = new int[order + 1];
	coeff[0] = 1;
}
Poly::Poly(int Order, int Default)
{
	order = Order;
	coeff = new int[order + 1];
	for (int i = 0; i <= order; i++)
	{
		coeff[i] = Default;
	}
}
Poly::Poly(int Order, int *Coeff)
{
	order = Order;
	coeff = new int[order + 1];
	for (int i = 0; i <= order; i++)
	{
		coeff[i] = Coeff[i];
	}
}
Poly::~Poly()
{
	delete[] coeff;
	coeff = nullptr;
}
Poly::Poly(const Poly &rhs)
{
	order = rhs.order;
	coeff = new int[order + 1];
	for (int i = 0; i <= order; i++)
	{
		coeff[i] = rhs.coeff[i];
	}
}
Poly &Poly::operator=(const Poly &rhs)
{
	order = rhs.order;
	coeff = new int[order + 1];
	for (int i = 0; i <= order; i++)
	{
		coeff[i] = rhs.coeff[i];
	}
	return *this;
}
void Poly::set(int coeff[], int size)
{
	order = size;
	for (int i = 0; i <= size; i++)
	{
		this->coeff[i] = coeff[i];
	}
}
int Poly::getOrder() const
{
	return order;
}
int *Poly::get() const
{
	return coeff;
}
Poly Poly::operator+(const Poly &rhs)
{
	Poly temp;
	int ch = 0;
	if (rhs.order <= order)
	{
		ch = rhs.order;
		temp = *this;
	}
	else
	{
		ch = order;
		temp = rhs;
	}
	for (int i = 0; i <= ch; i++)
	{
		temp.coeff[i] = coeff[i] + rhs.coeff[i];
	}
	return temp;
}
Poly Poly::operator-(const Poly &rhs)
{
	Poly temp;
	int ch = 0;
	if (rhs.order <= order)
	{
		ch = rhs.order;
		temp = *this;
	}
	else
	{
		ch = order;
		temp = rhs;
	}
	for (int i = 0; i <= ch; i++)
	{
		temp.coeff[i] = coeff[i] - rhs.coeff[i];
	}
	return temp;
}
Poly Poly::operator*(const int p)
{
	Poly temp(this->order, this->coeff);
	int ch = this->order;

	for (int i = 0; i <= ch; i++)
	{
		temp.coeff[i] = p * temp.coeff[i];
	}
	return temp;
}
bool Poly::operator==(const Poly &rhs)
{
	if (rhs.order != this->order)
	{
		return false;
	}
	else
	{
		int ch = this->order;
		for (int i = 0; i <= ch; i++)
		{
			if (rhs.coeff[i] != this->coeff[i])
			{
				return false;
			}
		}
		return true;
	}
}
int &Poly::operator[](int n)
{
	int ch = this->order;
	if (n <= ch)
	{
		return this->coeff[n];
	}
	return this->coeff[0];
}
const int &Poly::operator[](int i) const
{
	int ch = this->order;
	if (i <= ch)
	{
		return this->coeff[i];
	}
	return this->coeff[0];
}
int Poly::operator()(int x)
{
	int value = 0;
	for (int i = order; i >= 0; i--)
	{
		if (coeff[i] >= 0)
		{
			if (i == 0)
				value += 1;
			else
				value += pow(coeff[i], i);
		}
		else
		{
			if (i == 0)
				value += 1;
			else
				value += pow(coeff[i], i);
		}
	}
	return value;
}
Poly Poly::operator*(const Poly &rhs)
{
	int m = this->getOrder();
	int n = rhs.getOrder();
	int *prod = new int[m + n - 1];
	Poly multi(m + n - 1, 0);

	// Initialize the product polynomial
	for (int i = 0; i < m + n - 1; i++)
		multi.coeff[i] = 0;
	// Multiply two polynomials term by term

	// Take ever term of first polynomial
	for (int i = 0; i < m; i++)
	{
		// Multiply the current term of first polynomial
		// with every term of second polynomial.
		for (int j = 0; j < n; j++)
			multi.coeff[i + j] += this->coeff[i] * rhs.coeff[j];
	}

	return multi;
}
void Poly::show()
{
	cout << "Polynomial : ";
	for (int i = order; i >= 0; i--)
	{
		if (coeff[i] >= 0)
		{
			if (i == 0)
				cout << "+" << coeff[i];
			else
				cout << "+" << coeff[i] << "x^" << i;
		}
		else
		{
			if (i == 0)
				cout << coeff[i];
			else
				cout << coeff[i] << "x^" << i;
		}
	}
	cout << endl;
}
ostream &operator<<(ostream &Out, const Poly &p)
{
	Out << "Polynomial : ";
	for (int i = p.getOrder(); i >= 0; i--)
	{
		if (p.coeff[i] >= 0)
		{
			if (i == 0)
				Out << "+" << p.coeff[i];
			else
				Out << "+" << p.coeff[i] << "x^" << i;
		}
		else
		{
			if (i == 0)
				Out << p.coeff[i];
			else
				Out << p.coeff[i] << "x^" << i;
		}
	}
	Out << endl;
	return Out;
}