#include <iostream>
using namespace std;

int main()
{
    long arr[] = {4, 0, 9, 6};
    long *ptr = arr;
    ptr++;
    long *ptr2 = arr + 1;
    cout << *ptr2;

    return 0;
}