#include <stdio.h>

int adjacent_pair(int arr[], int s, int i)
{
    if(i >= s) 
        return 1;
    if (arr[i] <= arr[i + 1])
        adjacent_pair(arr, s, i + 2);
    else
    {
        return 0;
    }
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 0, 1, 10, 11};
    for (int i = 0; i < 10; i++){
        scanf("%d:", &arr[i]);
    }
        int a = adjacent_pair(arr, 10, 0);
    if(a== 1){
        printf("True");
    }
    else {
        printf("False ");
    }

    return 0;
}