#include <iostream>
using namespace std;

void cyclicRotate(int arr[], int d, int n)
{

    for (int i = 0; i < d; i++)
    {
        int x = arr[n - 1];
        for (int j = n - 1; j > 0; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[0] = x;
    }
}

int main()
{
    int arr[] = {3, 4, 5, 8, 7, 2, 9, 1};
    cyclicRotate(arr, 3, 8);
    for (int i = 0; i < 8; i++)
        cout << arr[i];
    return 0;
}