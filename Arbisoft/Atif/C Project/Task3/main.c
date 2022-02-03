#include <stdio.h>

int main()
{

    int run = 0;
    int choice = -1;

    while (choice != 0)
    {
        printf("\nEnter 0. Quit\n");
        printf("Enter 1. Farhenheit To Celsius\n");
        printf("Enter 2. Celsuis To Frahenheit\n");
        printf("Enter 3. Celsuis To Kelvin \n");
        printf("Enter 4. Kelvin To Celsuis\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("Quiting ");
            return 0;
            break;
        case 1:
        {
            double f, c;
            printf("Enter fahrenheit: ");
            scanf("%lf", &f);

            c = (f - 32) * 0.5556;
            printf("Celsius: %.2lf\n", c);
        }

        break;
        case 2:
        {
            double ff, cc;
            printf("Enter celsius:");
            scanf("%lf", &cc);

            ff = cc * 1.8 + 32;
            printf("Fahrenhiet:%.2lf\n", ff);
        }

        break;
        case 3:
        {
            float celsuis;
            printf("Enter temperature in celsius: ");
            scanf("%f", &celsuis);
            float kelvin;
            kelvin = 273.15 + celsuis;
            printf("%0.2f Celsius = %0.2f Kelvin\n", celsuis, kelvin);
        }
        break;
        case 4:
        {
            float kelvin;
            printf("Enter temperature in kelvin: ");
            scanf("%f", &kelvin);
            float celsius;
            celsius = 273.15 - kelvin;
            printf("%0.2f Kelvin = %0.2f Celsius\n", kelvin, celsius);
        }
        break;

        default:
            printf("Invalid Choice \n");
            break;
        }
    }

    return 0;
}