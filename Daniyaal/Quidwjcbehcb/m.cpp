#include <iostream>
using namespace std;

void func(int *arr, int m, int n) //function prototype
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *((arr + i * n) + j) = 0; // assigning value
        }
    }
}

int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    func((int *)arr, 3, 3); //function call
    return 0;
}
