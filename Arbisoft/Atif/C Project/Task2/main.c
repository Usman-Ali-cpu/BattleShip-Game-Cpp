#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>

long int Binary_to_Decimal(long int);
long int Binary_to_Hexadecimal(long int);
long int Decimal_to_Binary(long int);
long int Decimal_to_Hexadecimal(long int);
void Hexadecimal_to_Binary(char[]);
void Hexadecimal_to_Decimal(char[]);

int main()
{
    int operations, numbers = 1, checking;
    long int b, o, d;
    char h[100];
    int x, y, spacebar;

    printf("\t\tWELCOME TO NUMBER SYSTEM CONVERSION\n\n");

    while (numbers != 0)
    {
        printf("\t\t>>>>>> CHOOSE THE CONVERSION <<<<<<\n\n");

        printf("=> BINARY <=\n");
        printf("1: Binary to Decimal.\n2: Binary to Hexa-Decimal.\n");

        printf("\n=> DECIMAL <=\n");
        printf("3: Decimal to Binary.\n4: Decimal to Hexa-Decimal.\n");

        printf("\n=> HEXA-DECIMAL <=\n");
        printf("5: Hexa-Decimal to Binary.\n6: Hexa-Decimal to Decimal.\n");

        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &operations);

        switch (operations)
        {
        case 1:
            printf("\n***BINARY TO DECIMAL***\n");
        D:
            printf("\nEnter the Number in Binary form (0s & 1s): ");
            scanf("%ld", &b);

            checking = b;

            while (checking != 0)
            {
                numbers = checking % 10;
                if (numbers > 1)
                {
                    printf("\n%d IS NOT BINARY NUMBER.\n", b);
                    printf("***TRY AGAIN****\n");
                    goto D;
                }
                else
                    checking = checking / 10;
            }

            Binary_to_Decimal(b);
            break;

        case 2:
            printf("\n***BINARY TO HEXA-DECIMAL***\n");
        F:
            printf("\nEnter the Number in Binary form (0s & 1s): ");
            scanf("%ld", &b);

            checking = b;

            while (checking != 0)
            {
                numbers = checking % 10;
                if (numbers > 1)
                {
                    printf("\n%d IS NOT BINARY NUMBER.\n", b);
                    printf("***TRY AGAIN****\n");
                    goto F;
                }
                else
                    checking = checking / 10;
            }

            Binary_to_Hexadecimal(b);
            break;

        case 3:
            printf("\n***DECIMAL TO BINARY***\n");
            printf("\nEnter the Number in Decimal form (0 to 9): ");
            scanf("%ld", &d);
            Decimal_to_Binary(d);
            break;

        case 4:
            printf("\n***DECIMAL TO HEXA-DECIMAL***\n");
            printf("\nEnter the Number in Decimal form (0 to 9): ");
            scanf("%ld", &d);
            Decimal_to_Hexadecimal(d);

            break;

        case 5:
            printf("\n***HEXA-DECIMAL TO BINARY***\n");
        X:
            printf("\nEnter the Number in Hexa-Decimal form: ");
            scanf("%s", &h);
            //check
            for (x = strlen(h) - 1; x >= 0; x--)
            {
                if (h[x] > 'f' && h[x] <= 'z' || h[x] > 'F' && h[x] <= 'Z')
                {
                    printf("\nYou have to Enter Hexa-Decimal Number.\n");
                    printf("'%c' IS NOT Hexa-Decimal Number.\n", h[x]);
                    goto X;
                }
            }
            Hexadecimal_to_Binary(h);
            break;

        case 6:
            printf("\n***HEXA-DECIMAL TO DECIMAL***\n");
        Y:
            printf("\nEnter the Number in Hexa-Decimal form: ");
            scanf("%s", &h);
            //check
            for (x = strlen(h) - 1; x >= 0; x--)
            {
                if (h[x] > 'f' && h[x] <= 'z' || h[x] > 'F' && h[x] <= 'Z')
                {
                    printf("\nYou have to Enter Hexa-Decimal Number.\n");
                    printf("'%c' IS NOT Hexa-Decimal Number.\n", h[x]);
                    goto Y;
                }
            }
            Hexadecimal_to_Decimal(h);

            break;

        default:
            printf("\n***INVALID NUMBER***\n");
            break;
        }
        printf("\n\nDO YOU WANT TO CONTINUE = (1/0) :\n");
        scanf("%d", &numbers);
    }

    spacebar = 3 + 35;
    for (x = 1; x <= 3; x++)
    {
        for (y = 1; y <= spacebar; y++)
        {
            printf(" ");
        }
        spacebar--;
        for (y = 1; y <= 2 * x - 1; y++)
        {
            printf("*");
        }
        printf("\n");
    }
    spacebar = 37;
    for (x = 1; x <= 3; x++)
    {
        for (y = 1; y <= spacebar; y++)
        {
            printf(" ");
        }
        spacebar++;
        for (y = 1; y <= 2 * (3 - x) - 1; y++)
        {
            printf("*");
        }

        printf("\n");
    }
}

long int Binary_to_Decimal(long int bin)
{
    int remainder, summation = 0, x = 0;
    while (bin != 0)
    {
        remainder = bin % 10;
        bin = bin / 10;
        summation = summation + remainder * pow(2, x);
        x++;
    }

    printf("\nEquivalent Decimal Number : %d", summation);
}

long int Binary_to_Hexadecimal(long int bin)
{
    int remainder, x = 0, summation = 0, remaining[100], length = 0;

    while (bin != 0)
    {
        remainder = bin % 10;
        bin = bin / 10;
        summation = summation + remainder * pow(2, x);
        x++;
    }
    x = 0;
    while (summation != 0)
    {
        remaining[x] = summation % 16;
        summation = summation / 16;
        x++;
        length++;
    }
    printf("\nEquivalent Hexa-Decimal Number : ");
    for (x = length - 1; x >= 0; x--)
    {
        switch (remaining[x])
        {
        case 10:
            printf("A");
            break;

        case 11:
            printf("B");
            break;

        case 12:
            printf("C");
            break;

        case 13:
            printf("D");
            break;

        case 14:
            printf("E");
            break;

        case 15:
            printf("F");
            break;

        default:
            printf("%d", remaining[x]);
        }
    }
}

long int Decimal_to_Binary(long int dec)
{
    int remainder[50], x, length = 0;
    do
    {
        remainder[x] = dec % 2;
        dec = dec / 2;
        x++;
        length++;
    } while (dec != 0);

    printf("\nEquivalent Binary Number : ");
    for (x = length - 1; x >= 0; x--)
    {
        printf("%d", remainder[x]);
    }
}

long int Decimal_to_Hexadecimal(long int dec)
{
    int remainder[50], x, length = 0;
    do
    {
        remainder[x] = dec % 16;
        dec = dec / 16;
        x++;
        length++;
    } while (dec != 0);

    printf("\nEquivalent Hexa-Decimal Number : ");
    for (x = length - 1; x >= 0; x--)
    {
        switch (remainder[x])
        {
        case 10:
            printf("A");
            break;

        case 11:
            printf("B");
            break;

        case 12:
            printf("C");
            break;

        case 13:
            printf("D");
            break;

        case 14:
            printf("E");
            break;

        case 15:
            printf("F");
            break;

        default:
            printf("%d", remainder[x]);
        }
    }
}

void Hexadecimal_to_Binary(char hex[])
{
    int x = 0;
    printf("\nEquivalent Binary Number : ");
    for (x = 0; x < strlen(hex); x++)
    {
        switch (hex[x])
        {
        case '0':
            printf("0000");
            break;
        case '1':
            printf("0001");
            break;
        case '2':
            printf("0010");
            break;
        case '3':
            printf("0011");
            break;
        case '4':
            printf("0100");
            break;
        case '5':
            printf("0101");
            break;
        case '6':
            printf("0110");
            break;
        case '7':
            printf("0111");
            break;
        case '8':
            printf("1000");
            break;
        case '9':
            printf("1001");
            break;
        case 'A':
        case 'a':
            printf("1010");
            break;
        case 'B':
        case 'b':
            printf("1011");
            break;
        case 'C':
        case 'c':
            printf("1100");
            break;
        case 'D':
        case 'd':
            printf("1101");
            break;
        case 'E':
        case 'e':
            printf("1110");
            break;
        case 'F':
        case 'f':
            printf("1111");
            break;

        default:
            printf("\n Invalid hexa digit %c ", hex[x]);
        }
    }
}

void Hexadecimal_to_Decimal(char hex[])
{
    int x, numbers = 0, powered = 0, decimal = 0;

    for (x = strlen(hex) - 1; x >= 0; x--)
    {
        if (hex[x] == 'A' || hex[x] == 'a')
        {
            numbers = 10;
        }
        else if (hex[x] == 'B' || hex[x] == 'b')
        {
            numbers = 11;
        }
        else if (hex[x] == 'C' || hex[x] == 'c')
        {
            numbers = 12;
        }
        else if (hex[x] == 'D' || hex[x] == 'd')
        {
            numbers = 13;
        }
        else if (hex[x] == 'E' || hex[x] == 'e')
        {
            numbers = 14;
        }
        else if (hex[x] == 'F' || hex[x] == 'f')
        {
            numbers = 15;
        }
        else
        //(a[i]>=0 || a[i]<=9)
        {
            numbers = hex[x] - 48;
        }

        decimal = decimal + numbers * pow(16, powered);
        powered++;
    }
    printf("\nEquivalent Decimal Number : %d", decimal);
}
