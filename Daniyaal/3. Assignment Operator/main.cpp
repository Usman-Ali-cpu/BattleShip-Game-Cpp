#include <iostream>
using namespace std;

class Point
{
private:
    float x, y;

public:
    Point(float i = 0, float j = 0)
    {
        x = i;
        y = j;
    }
    void print()
    {
        cout << " x = " << x << ", y = " << y;
    }
    Point &operator++();
    Point operator++(int);

    friend ostream &operator<<(ostream &out, const Point &p);
};
/*********************** Code need to paste ***************************/
ostream &operator<<(ostream &out, const Point &p)
{
    out << "(" << p.x << "," << p.y << ")";
    return out;
}
Point Point::operator++(int dem)
{
    Point temp;
    temp.x = x++;
    temp.y = y++;
    return temp;
}

Point &Point::operator++()
{
    x++;
    y++;
    return *this;
}
/*************************** END CODE ******************************/
int main()
{
    Point t(20, 20);
    ++t;
    Point t1(30, 30);
    t1 = t++;
    cout << t << " " << t1;
    return 0;
}
