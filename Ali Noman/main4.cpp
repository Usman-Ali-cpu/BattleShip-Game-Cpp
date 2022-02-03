#include <iostream>
using namespace std;

int main()
{
    /*
    Part(i)
    We need a copy constructor when we need to initialize a object with already
    existing object while creating new object. We need copy constructor on that moment
    The copy constructor which is default in c++ object only copy the object, not all members one by one
    so we create copy contructor so we can initialize each member of object.

Part(ii)
Arrays and pointers are intimately related in C++ and may be used almost interchangeably.
An array name can be thought of as a constant pointer. It refers directly to the elements.
Pointers can be used to do any operation involving array subscripting. 	It refers address of the variable.
Assume the following declarations:
int myArray[ ] = {2,4,6};
int *myArray = new int{2,4,6};
Here one declartion is using simple array
and other is with pointer.
Accessing syntax:
for Array:
myArray[0] = 2;
myArray[1] = 4;
myArray[2] = 6;
for pointer:
*( myArray + 0 ) = 2
*( myArray + 1 ) = 4
*( myArray + 2 ) = 6




    */

    return 0;
}