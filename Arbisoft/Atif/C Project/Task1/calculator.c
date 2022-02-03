#include <stdio.h>
#include <stdlib.h>

int main()
{
    char op;
    int i = 0;
    double first, second;
    while (op != 'q')
    {
        printf("\n\t\tEnter an operator (+, -, *, /)(q/ Quit):  ");
        if (i > 0)
        {
            char ch = getchar();
        }
        i++;
        scanf("%c", &op);
        if (op == 'q')
        {
            printf("Calculator is Terminating\n");
            return 0;
        }
        printf("\nTwo operands: ");
        printf("\nEnter first operands: ");
        scanf("%lf", &first);
        printf("Enter second operands: ");
        scanf("%lf", &second);

        switch (op)
        {
        case '+':
            printf("%.1lf + %.1lf = %.1lf", first, second, first + second);
            break;
        case '-':
            printf("%.1lf - %.1lf = %.1lf", first, second, first - second);
            break;
        case '*':
            printf("%.1lf * %.1lf = %.1lf", first, second, first * second);
            break;
        case '/':
            printf("%.1lf / %.1lf = %.1lf", first, second, first / second);
            break;
        // operator doesn't match any case constant
        default:
            printf("Error! operator is not correct");
        }
    }
    return 0;
}
