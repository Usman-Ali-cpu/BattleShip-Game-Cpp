#include <stdio.h>
#include <stdbool.h>

bool magicMatrix(int matrix[5][4])
{
    int i = 0, j = 0;
    int sum1 = 0, sum2 = 0;
    for (i = 0; i < 5; i++)
    {
        sum1 = 0;
        if (i % 2 != 1)
        {
            for (j = 0; j < 4; j++)
            {
                sum1 += matrix[i][j];
            }
        }
        int b, a;
        for (b = 0; b < 4; b++)
        {
            sum2 = 0;
            {
                for (a = 0; a < 5; a++)
                {
                    if (b % 2 == 1)
                    {
                        sum2 += matrix[a][b];
                    }
                }
                if (sum2 == sum1)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int matrix[5][4];
    int i, j;
    printf("Enter 5x4 matrix\n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    if (magicMatrix(matrix))
    {
        printf("Magic Matrix");
        return 0;
    }
    printf("Not Magic Matrix");
    return 0;
}