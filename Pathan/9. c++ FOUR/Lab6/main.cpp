#include <iostream>

using namespace std;

void sum(int &x, int y, int &z)
{
    x = x + 1;
    z = x + y;
    y = z;
}

int main()
{
    int list1[5], list2[5];
    int a = 3, b = 5, c = 2;

    for (int i = 0; i < 5; i++)
    {
        list1[i] = i + 2;
        list2[i] = i + 1;
    }
    // A
    sum(a, b, c);
    cout << "a =  " << a << " - b = " << b << " - c = " << c << endl;

    // B
    a = list1[4];
    b = list2[3];
    sum(a, b, c);
    cout << "a =  " << a << " - b = " << b << " - c = " << c << endl;

    // C
    // sum(list1, list2, c);
    // cout << "list1 =  " << list1 << " - list2 = " << list2 << " - c = " << c << endl;

    // D
    a = list1[2];
    b = list2[1];
    sum(a, b, c);
    cout << "a =  " << a << " - b = " << b << " - c = " << c << endl;
    return 0;
}
