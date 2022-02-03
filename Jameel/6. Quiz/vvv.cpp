#include <iostream>
using namespace std;
struct Data
{
    int calories;
};
class Archive
{
    Data *store[3];
    int num;

public:
    Archive(Data appData[], int m)
    {
        for (int i = 0; i < m; i++)
            *store[i] = appData[i];
        num = m;
    }
    Archive(const Archive &a) { this = a; }
    Archive operator=(Archive &d)
    {
        d = *this;
        if (num > 0)
            --num;
        return *this;
    }
    ~Archive() { delete[] store; }
    ostream operator<<(ostream &os, const Archive &z)
    {
        os << z.num << endl;
        return os;
    }
};

int main()
{
    Data arr[] = {1, 23};
    Archive a(arr, 2);
    return 0;
}
// line 0022
// type:  compile error
// problem: ostream operator is implemented inside the class
// fix : use friend keyword and implement outside the class

// line 0012
// type: compile error
// problem: assigning Data to Data* type
// fix: do derefer, *store[i] = appData[i];

// line 0017
// type: logical error
// problem: assigning Data to Archive type
// fix: change the type Data to Archive

// line 0019
// type: compile error
// problem: not returning the pointer of refernece type
// fix: use *this instead of this

// line 0015
// type: compile error
// problem: passing const Archive
// fix:  Archive(const Archive &a) { *this = a; }

// line 0016
// type: logical error
// problem: passing Book instead of Archive object
// fix: Archive operator=(Archive &d)

// line 0022
// type: compile
// problem: not making friend
// fix: friend ostream operator<< (ostream& os, const Archive& z);