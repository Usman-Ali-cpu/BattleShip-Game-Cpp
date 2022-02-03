#include <stdio.h>

int main()
{
    float pin[5], val = 9.7, *ptrf;
    int mat[9], *ptrk;
    // scanf("%d", mat + 3);
    // printf("%d\n", mat + 3);
    // *pin = pin[6];
    // scanf("%d", &mat + 3); // not true because assigning value to address of array
    // printf("%f", *pin); // true, it is assigning value of sixth index to first index by de refering,
    //&pin[2] = ptrf // false  can not get adddress of index of array by using &
    //pin[3] = ptrf; // false can not assign value of pointer to int type variable
    //pin = ptrf; // false because pointer can not be store in address of array
    //ptrf = mat+10; // is true because we can assing address of array to pointer
    // mat + 5 = ptrk; // is false because we can not assign address of array to pointer
    // val =(float) (*mat[3]); // it is flase , because we can not derefer element at index of array
    // printf("%c", *ptrk + 3); // it true, because we can using pointer to add integer in it after dereferencing
    // *ptrk = (*pin + 2); // it is true, because we can assign value to pointer by dereferencing
    return 0;
}
