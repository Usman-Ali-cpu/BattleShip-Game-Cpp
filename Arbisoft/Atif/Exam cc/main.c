#include <stdio.h>

int *matrices(int pin[], int mat[], int N)
{
    int *ptr;
    for (int i = 0; i < N; i++)
    {
        if (pin[i] != mat[i])
        {
            ptr = &i;
            return ptr;
        }
        else
        {
            pin[i] = 0;
            mat[i] = 0;
        }
    }
    return NULL;
}
int main()
{
    const int N = 10;
    int pin[10] = {0};
    int mat[10] = {0};
    if (matrices(pin, mat, 10) == NULL)
    {
        printf("null");
    }
    else
    {
        int *ptr;
        *ptr = matrices(pin, mat, 10) == NULL;
        printf("Value: %d\n", *ptr);
        printf("Address: %d", ptr);
    }

    return 0;
}