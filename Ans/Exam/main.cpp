#include <iostream>
using namespace std;

bool isMagic(int mat[5][4])
{
    // int n = my_sizeof(mat) / my_sizeof(mat[0]);
    // calculate the sum of
    // the prime diagonal
    int i = 0, j = 0;
    // sumd1 and sumd2 are the sum of the two diagonals
    int sumd1 = 0, sumd2 = 0;
    for (i = 0; i < 5; i++)
    {
        sumd1 = 0;
        if (i % 2 == 0)
        {
            for (j = 0; j < 4; j++)
            {
                sumd1 += mat[i][j];
            }
        }
        for (int k = 0; k < 4; k++)
        {
            sumd2 = 0;
            {
                for (int a = 0; a < 5; a++)
                {
                    if (k % 2 != 0)
                    {
                        sumd2 += mat[a][k];
                    }
                }
                if (sumd2 == sumd1)
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
    int matix[5][4];
    /*Counter variables for the loop*/
    int i, j;
    printf("Please enter 5x4 matix\n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4; j++)
        {
            // printf("[%d][%d]:", i, j);
            scanf("%d", &matix[i][j]);
        }
    }
    if (isMagic(matix))
    {
        printf("Magic Matrix");
    }
    else
    {
        printf("Not Magic Matrix");
    }

    return 0;
}