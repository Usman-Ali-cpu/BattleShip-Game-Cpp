#include <stdio.h>
#include <stdbool.h>

int main()
{
    char number[20];
    printf("Enter Student number: ");
    scanf("%s", &number);

    if (number[4] == '1' && number[3] == '0')
    {
        printf("Information Technology");
    }
    else if (number[4] == '2' && number[3] == '0')
    {
        printf("Engineering");
    }
    else if (number[4] == '3' && number[3] == '0')
    {
        printf("Business");
    }
    else if (number[4] == '4' && number[3] == '0')
    {
        printf("Medicine");
    }
    else
    {
        printf("UNKNOWN");
    }

    return 0;
}