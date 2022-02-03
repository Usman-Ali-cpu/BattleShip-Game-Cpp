#include <iostream>
#include <math.h>
using namespace std;

class Complex
{
private:
    float real;
    float imaginary;

public:
    Complex(float real = 0, float a_img = 0)
    {
        this->imaginary = a_img;
        this->real = real;
    }
    void set(float real, float a_img)
    {
        this->imaginary = a_img;
        this->real = real;
    }
    float getReal()
    {
        return this->real;
    }
    float getImg()
    {
        return this->imaginary;
    }
    void print()
    {
        cout << this->real << " + i" << this->imaginary << endl;
    }
    Complex operator+=(Complex &c2)
    {
        return Complex(this->getReal() + c2.getReal(), this->getImg() + c2.getImg());
    }
    bool operator&&(Complex &c)
    {
        float first = sqrt(this->getReal() * this->getReal() + this->getImg() * this->getImg());
        float second = sqrt(c.getReal() * c.getReal() + c.getImg() * c.getImg());
        if (first < 10 && second < 10)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Complex u, v(-1, 7);
    u.set(3, 5);
    v += u;
    cout << "The new object is : ";
    v.print();
    cout << endl;
    if (u && v)
    {
        cout << "Magnitude of both complex numbers are less than 10\n";
    }
    else
    {
        cout << "Magnitude of both complex numbers are not less than 10\n";
    }

    return 0;
}