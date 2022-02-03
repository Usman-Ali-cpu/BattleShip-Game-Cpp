#include <stdio.h>

void sum(int arr[], int size)
{
    for (int i = 0; i < 6; i++)
    {
        int num = arr[i];
        for (int j = 0; j < 5; j++)
        {
            if (arr[i] != arr[j])
            {
                if (arr[j] * arr[j + 1] == arr[i])
                {
                    printf("%d = %d * %d\n", arr[i], arr[j], arr[j + 1]);
                }
                if (j > 0)
                {
                    if (arr[j] * arr[j - 1] == arr[i])
                    {
                        printf("%d = %d * %d\n", arr[i], arr[j], arr[j + 1]);
                    }
                }
            }
        }
    }
}
int main()
{
    int arr[] = {6, 2, 3, 4, 8, 12};
    sum(arr, 6);

    return 0;
}