#include <stdio.h>

int findPosition(char c)
{
    char alphabet[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i;
    for (i = 0; i < 26; i++)
    {
        if (c == alphabet[i])
        {
            return i + 1;
        }
    }
}
int main()
{
    char string1[10], string2[10];
    printf("String 1:");
    scanf("%s", &string1);
    printf("String 2:");
    scanf("%s", &string2);
    char c1, c2;

    int a, b, c;

    c1 = string1[0];
    c2 = string2[0];
    int p1 = findPosition(c1);
    int p2 = findPosition(c2);
    a = (p1 - p2) * (p1 - p2);

    c1 = string1[1];
    c2 = string2[1];

    p1 = findPosition(c1);
    p2 = findPosition(c2);
    b = (p1 - p2) * (p1 - p2);

    c1 = string1[2];
    c2 = string2[2];
    p1 = findPosition(c1);
    p2 = findPosition(c2);
    c = (p1 - p2) * (p1 - p2);

    int distance = a + b + c;
    printf("Distance is = %d ", distance);
    return 0;
}