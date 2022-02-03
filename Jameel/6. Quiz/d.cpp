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
    Library(Library &a) { *this = a; }
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
}

// line 0010
// type: invalid data type passing
// problem: passing simple array to assign to pointer array
// fix: derefer at line 0012, like this  *catalog[i] = appBook[i];

// line 0012
// type: invalid assignment
// problem: assing int to pointer
// fix: derefer , like this  *catalog[i] = appBook[i];

// line 0016
// type: invalid assignment  of object
// problem: passing Book instead of Library object
// fix: Library operator=(Library &d)

// line 0015
// type: invalid assignment , no operator for Library to const Library assignment
// problem: passing const Library
// fix:  Library(const Library &a) { *this = a; }

// line 0017
// type: invalid assignment  of object
// problem: passing Book instead of Library object
// fix: Library operator=(Library &d)

// line 0019
// type: invalid return type
// problem: return this not derefering
// fix: return *this

// line 0022
// type: operator<< cannot be implement in side class
// problem: not making friend
// fix: friend ostream operator<< (ostream& os, const Library& z);

// There are seven bugs in the following C++ program. For each bug, identify its line number,
// the type of the error, the nature of the error and how to fix it in the following format.
// Note: If the line number does not correspond to the location of the bug/problem, the marks
// for the answer will be ZERO regardless of its correctness.

// line: ???

// type: type of error  (1 mark)

// Problem: the nature of error or bug (2 marks)

// Fix: How to fix it: (2 marks)

//  Example:

//  line: 22

// Type: run time error

// Problem: deleting uninitialized pointer var.

// Fix: var = nullptr;
