#include <stdio.h>

void divide(float *a, int *b) // function takes two arguments, one is pointer to float and one is pointer to int
{
    *a = *b / *a; // value pointed by int pointer divided by  value pointed by float pointer will be store in float pointer's value
}

int main()
{

    float num1 = 10;
    int num2 = 20;
    divide(&num1, &num2); // passing address of int and float
    printf("%.2f", num1); // printing result

    return 0;
}