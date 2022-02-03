#include <iostream>
using namespace std;
struct Book
{
    int pages;
};
class Library
{
    Book *catalog[3];
    int num;

public:
    Library(Book appBook[], int m)
    {
        for (int i = 0; i < m; i++)
            *catalog[i] = appBook[i];
        num = m;
    }
    Library(const Library &a) { *this = a; }
    Library operator=(Library &d)
    {
        d = *this;
        if (num > 0)
            --num;
        return *this;
    }
    ~Library() { delete[] catalog; }
    ostream operator<<(ostream &os, const Library &z)
    {
        os << z.num << endl;
        return os;
    }
};