#include <stdio.h>
#include <stdbool.h>

float areaOfCircle(int rad)
{
    return (3.14 * rad * rad);
}

float periOfCircle(int rad)
{
    return (2 * 3.14 * rad);
}

int areaOfReactangle(int len, int wid)
{
    return len * wid;
}

int periOfRectangle(int len, int wid)
{
    return (2 * (len + wid));
}

int main()
{
    /* 2D array declaration*/
    while (true)
    {
        printf("\n\nEnter 1. For Area of Circle \n");
        printf("Enter 2. For Perimeter of Circle \n");
        printf("Enter 3. For Area of Rectangle \n");
        printf("Enter 4. For Perimeter of Rectangle \n");
        printf("Enter 5. To Quit \n");
        printf("Enter :  ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int rad;
            printf("Enter Raduis : ");
            scanf("%d", &rad);
            printf("Area of Circle is : %.2f", areaOfCircle(rad));
        }

        break;
        case 2:
        {

            int r;
            printf("Enter Raduis : ");
            scanf("%d", &r);
            printf("Perimeter of Circle is : %.2f", periOfCircle(r));
        }
        break;
        case 3:
        {

            int l, w;
            printf("Enter length : ");
            scanf("%d", &l);
            printf("Enter width : ");
            scanf("%d", &w);
            printf("Area of Rectangle : %d", areaOfReactangle(l, w));
        }
        break;
        case 4:
        {

            int len, wid;
            printf("Enter length : ");
            scanf("%d", &len);
            printf("Enter width : ");
            scanf("%d", &wid);
            printf("Area of Rectangle : %d", periOfRectangle(len, wid));
        }
        break;
        case 5:
            return 0;
            break;
        // operator doesn't match any case constant
        default:
            printf("Error! Choice is not correct");
        }
    }

    return 0;
}