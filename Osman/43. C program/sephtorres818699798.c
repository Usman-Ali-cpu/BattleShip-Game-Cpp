#include <stdio.h>
#include <stdlib.h>

extern float computeArea(int *, int *, int); // function prototype, take two pointers to int, and one int shape, and find area of specific shape
extern int numTimesAppears(char *, char);    // function prototype, take two parameter, one is string and other a char, return occurance of that char in string

/*

DESCRIPTION : 

This Program doing two functions. One it finds number of occurance of a character in the given string 
And secondly it finds area of shapes like(Triangle, Circle and Rectangle/Square)
One function take one string and one char as argument, it return number of occurance of that character in given string.
One function taks two pointer to int for dimensions of shape and one int for type of shape (1:triangle, 2:Rectangle, 3:Circle)
it finds area from given dimensions and return area.

*/

int main()
{
    int i;
    char mystring[100] = "Yusuf Ozturk";
    char ch;
    float area;
    int length, height, diameter, base;

    int count;

    base = 25;
    length = 25;
    height = 10;
    diameter = 5;

    area = computeArea(&base, &height, 1);
    printf("\nThe area of the triangle is %.3f", area);

    area = computeArea(&diameter, &diameter, 3);
    printf("\nThe area of a circle is %.3f", area);

    ch = 'u';
    count = numTimesAppears(mystring, ch);
    printf("\nNumber of times %c appears in string is %d", ch, count);

    return 0;
}

float computeArea(int *v1, int *v2, int shape)
{
    if (shape == 1) // check if shape is 1 ,it will be triangle
    {
        float area = *v1 * *v2 * 0.5; // formula =  base * height * 1/2
        return area;
    }
    else if (shape == 2) // check if shape is 2 ,it will be rectangle
    {
        float area = *v1 * *v2; // formula =  length * width
        return area;
    }
    else if (shape == 3) // check if shape is 3 ,it will be circle
    {
        float area = 0.25 * 3.14 * *v1 * *v1; // formula =  PI * diameter^2 * 1/4
        return area;
    }
}

int numTimesAppears(char *mystring, char ch)
{
    int i, count = 0;
    for (i = 0; mystring[i]; i++) // loop through whole string .
    {
        if (mystring[i] == ch) // checck if character at index i is eqaul to character in argument
        {
            count++; // increment the count
        }
    }
    return count; // return count of character
}
