#include <iostream>
#include <math.h>
using namespace std;

class Shape
{
private:
    double x, y;

public:
    Shape(double x, double y)
    {
        if (x != y)
        {
            if (x < y)
            {
                this->x = y;
                this->y = y;
            }
            else
            {
                this->x = x;
                this->y = x;
            }
        }
        else
        {
            this->x = x;
            this->y = y;
        }
    }

    void setX(double x)
    {
        if (x < 6)
        {
            this->x = 6;
        }
        else
        {
            this->x = x;
        }
    }

    double getX()
    {

        return x;
    }

    void setY(double y)
    {

        if (y < 6)
        {
            this->y = 6;
        }
        else
        {
            this->y = y;
        }
    }

    double getY()
    {

        return y;
    }
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
    virtual void adraw() = 0;
    virtual double getVolume()
    {
        return 0;
    };
    virtual string getType() = 0;
};
class Circle : public Shape
{

private:
    float radius;

public:
    Circle(double x, double y) : Shape(x, y)
    {
        radius = ((x * x) / (8 * y) + y / 2);
        cout << "Radius = " << radius << endl;
    }
    float getRadius()
    {
        return radius;
    }

    void setHeight(double h)
    {
        this->setY(h);
    }
    void setWidth(double w)
    {
        this->setX(w);
    }
    string getType()
    {
        return "Cricle";
    }
    double getArea()
    {
        return radius * radius * 3.14;
    }
    double getPerimeter()
    {
        return 2 * 3.14 * radius;
    }
    void adraw()
    {
        float r = this->radius;
        float pr = 2;                 // pr is the aspected pixel ratio which is almost equal to 2
        for (int i = -r; i <= r; i++) // loop for horizontal movement
        {
            for (int j = -r; j <= r; j++) // loop for vertical movement
            {
                float d = ((i * pr) / r) * ((i * pr) / r) + (j / r) * (j / r); // multiplying the i variable with pr to equalize pixel-width with the height
                if (d > 0.95 && d < 1.08)                                      // approximation
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
};

class Sphere : public Circle
{
public:
    Sphere(int w, int h) : Circle(w, h)
    {
    }
    double getArea()
    {
        return 4 * 3.14 * getRadius() * getRadius();
    }
    string getType()
    {
        return "Sphere";
    }
    double getVolume()
    {
        return (1.33) * 3.14 * getRadius() * getRadius() * getRadius();
    }
};

int main()
{
    Shape *c = new Circle(20, 20);
    cout << "Type: " << c->getType() << endl;
    cout << "Area: " << c->getArea() << endl;
    cout << "Perimeter: " << c->getPerimeter() << endl;
    c->adraw();
    c = new Sphere(20, 20);
    cout << "Type: " << c->getType() << endl;
    cout << "Area: " << c->getArea() << endl;
    cout << "Volume: " << c->getVolume() << endl;

    return 0;
}
